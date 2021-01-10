package webscrap;

import java.util.List;
import webscrap.MyUtil.Pair;
import com.gargoylesoftware.htmlunit.WebClient;
import com.gargoylesoftware.htmlunit.html.HtmlElement;
import com.gargoylesoftware.htmlunit.html.HtmlPage;
import com.gargoylesoftware.htmlunit.WebRequest;
import com.gargoylesoftware.htmlunit.HttpMethod;
import java.net.URL;

/**
 * @author AntKerf
 */
public class WebScrap {

    private static WebClient webClient;
    //основная страница
    private static HtmlPage mainPage;
    //страница с котировками по выбранной бирже
    private static HtmlPage stockPage;
    //номер биржи из списка на главной странице
    private static int currentIndexStock = 0;

    public static void init() {
        try {
            webClient = new WebClient();
            webClient.getOptions().setCssEnabled(false);
            webClient.getOptions().setJavaScriptEnabled(false);
            mainPage = webClient.getPage("http://ru.investing.com/equities/");
            stockPage = webClient.getPage("http://ru.investing.com/equities/StocksFilter?noconstruct=1&smlID=0&sid=&tabletype=price&index_id=13666");
        } catch (Exception ex) {
            new MyUtil.ErrorDialog(ex);
        }
    }

    //загрузка страницы с котировками выбранной биржы из списка
    public static void loadStock(int index_stock) {
        try {
            //список всех бирж
            List<HtmlElement> items = mainPage.getByXPath("/html[1]/body[1]/div[5]/section[1]/div[6]/select[1]/option");
            //ид биржы по ее номеру в списке
            String stock_id = items.get(index_stock).getAttribute("id");
            //страница с котировками
            stockPage = webClient.getPage("http://ru.investing.com/equities/StocksFilter?noconstruct=1&smlID=0&sid=&tabletype=price&index_id=" + stock_id);
            //установка выбранного номера биржы как текущий
            currentIndexStock = index_stock;

        } catch (Exception ex) {
            ex.printStackTrace();
        }

    }

    //загруза котировок со страницы выбранной биржи
    public static Object[][] data() {
        Object[][] data;
        try {
            //получение строк из таблицы с котироками
            List<HtmlElement> items = stockPage.getByXPath("/html[1]/body[1]/div[1]/table[1]/tbody[1]/tr");
            data = new Object[items.size()][8];
            for (int i = 0; i < items.size(); i++) {
                //Название
                data[i][0] = ((HtmlElement) items.get(i).getByXPath("td[2]").get(0)).asText();
                //Цена
                data[i][1] = ((HtmlElement) items.get(i).getByXPath("td[3]").get(0)).asText();
                //Макс
                data[i][2] = ((HtmlElement) items.get(i).getByXPath("td[4]").get(0)).asText();
                //Мин.
                data[i][3] = ((HtmlElement) items.get(i).getByXPath("td[5]").get(0)).asText();
                //Изм.
                data[i][4] = ((HtmlElement) items.get(i).getByXPath("td[6]").get(0)).asText();
                //Изм.%
                data[i][5] = ((HtmlElement) items.get(i).getByXPath("td[7]").get(0)).asText();
                //Объем
                data[i][6] = ((HtmlElement) items.get(i).getByXPath("td[8]").get(0)).asText();
                //Время
                data[i][7] = ((HtmlElement) items.get(i).getByXPath("td[9]").get(0)).asText();
            }
            //возращаем массив с данными для вставки в таблицу
            return data;
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        //при ошибке ничего не возращаем
        return null;
    }

    //загрузка дополнительной информации по акции
    public static Pair<Object[][], Integer[]> historyEquitie(int row) throws Exception {

        Object[][] data;//таблица с историей

        //получение ссылки на страницу с допинформацией
        String href;
        href = ((HtmlElement) stockPage.getFirstByXPath("/html[1]/body[1]/div[1]/table[1]/tbody[1]/tr[" + (row + 1) + "]/td[2]/a[1]")).getAttribute("href");
        //форматирование ссылки на страницу
        String URL = "http://ru.investing.com" + href.split("\\?")[0] + "-historical-data";
        if (href.contains("\\?")) {
            URL = URL + "?" + href.split("\\?")[1];
        }
        //загрузка данных

        HtmlPage EquititePage = webClient.getPage(URL);

        //получение id акции для ajax запросов по определенному периоду времени
        String idInfo = EquititePage.getFirstByXPath("/html[1]/body[1]/div[5]/section[1]/script[3]").toString();
        idInfo = idInfo.substring(idInfo.indexOf("{") + 1, idInfo.indexOf("}")).replaceAll("\\s", "");
        int pairId = Integer.valueOf(idInfo.split(",")[0].split(":")[1]);
        int smlId = Integer.valueOf(idInfo.split(",")[1].split(":")[1]);
        Integer[] IdInfo = new Integer[2]; //массив с id
        IdInfo[0] = pairId;
        IdInfo[1] = smlId;
        //получение данных за последний месяц по акции(по умолчанию)
        List<HtmlElement> items = EquititePage.getByXPath("/html[1]/body[1]/div[5]/section[1]/div[9]/table[1]/tbody[1]/tr");
        data = new Object[items.size()][7];
        for (int i = 0; i < items.size(); i++) {
            //Дата
            data[i][0] = ((HtmlElement) items.get(i).getByXPath("td[1]").get(0)).asText();
            //Цена
            data[i][1] = ((HtmlElement) items.get(i).getByXPath("td[2]").get(0)).asText();
            //Откр.
            data[i][2] = ((HtmlElement) items.get(i).getByXPath("td[3]").get(0)).asText();
            //Макс.
            data[i][3] = ((HtmlElement) items.get(i).getByXPath("td[4]").get(0)).asText();
            //Мин.
            data[i][4] = ((HtmlElement) items.get(i).getByXPath("td[5]").get(0)).asText();
            //Объем
            data[i][5] = ((HtmlElement) items.get(i).getByXPath("td[6]").get(0)).asText();
            //Изм.%
            data[i][6] = ((HtmlElement) items.get(i).getByXPath("td[7]").get(0)).asText();
        }
        return new Pair<>(data, IdInfo);
    }

    //загрузка названий бирж
    public static String[] stockNames() {
        String stocks[];
        try {
            //получение всех индексов из списка
            List<HtmlElement> items = mainPage.getByXPath("/html[1]/body[1]/div[5]/section[1]/div[6]/select[1]/option");
            stocks = new String[items.size()];
            for (int i = 0; i < items.size(); i++) {
                //вывод всех названий
                stocks[i] = items.get(i).asText();
            }
            return stocks;
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return null;
    }

    //получение прошлых данных акции через Ajax скрипт посредством post запроса
    public static Object[][] postHistoryReq(int pairId, int smlId, String st_date, String end_date, String interval) {
        try {
            URL url = new URL("https://ru.investing.com/instruments/HistoricalDataAjax");
            WebRequest requestSettings = new WebRequest(url, HttpMethod.POST);

            requestSettings.setAdditionalHeader("Host", "ru.investing.com");
            requestSettings.setAdditionalHeader("Connection", "keep-alive");
            requestSettings.setAdditionalHeader("Accept", "text/plain, */*; q=0.01");
            requestSettings.setAdditionalHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36");
            requestSettings.setAdditionalHeader("Content-Type", "application/x-www-form-urlencoded");
            requestSettings.setAdditionalHeader("Sec-Fetch-Site", "same-origin");
            requestSettings.setAdditionalHeader("X-Requested-With", "XMLHttpRequest");
            requestSettings.setAdditionalHeader("Sec-Fetch-Mode", "cors");
            requestSettings.setAdditionalHeader("Sec-Fetch-Dest", "empty");
            requestSettings.setAdditionalHeader("Accept-Encoding", "identity");
            requestSettings.setAdditionalHeader("Accept-Language", "ru-RU,ru;q=0.9,en-US;q=0.8,en;q=0.7");
            requestSettings.setAdditionalHeader("Origin", "https://ru.investing.com");
            //  requestSettings.setAdditionalHeader("Referer", "https://ru.investing.com/equities/polymetal-historical-data?cid=44465");
            requestSettings.setRequestBody("curr_id=" + pairId + "&smlID=" + smlId + "&header=%D0%9F%D1%80%D0%BE%D1%88%D0%BB%D1%8B%D0%B5+%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D0%B5+-+POLY&st_date=" + st_date + "&end_date=" + end_date + "&interval_sec=" + interval + "&sort_col=date&sort_ord=DESC&action=historical_data");
            HtmlPage redirectPage = webClient.getPage(requestSettings);
            //парсинг полученной страницы
            Object[][] data;
            List<HtmlElement> items = redirectPage.getByXPath("/html[1]/body[1]/div[1]/table[1]/tbody[1]/tr");
            data = new Object[items.size()][7];
            for (int i = 0; i < items.size(); i++) {
                //Дата
                data[i][0] = ((HtmlElement) items.get(i).getByXPath("td[1]").get(0)).asText();
                //Цена
                data[i][1] = ((HtmlElement) items.get(i).getByXPath("td[2]").get(0)).asText();
                //Откр.
                data[i][2] = ((HtmlElement) items.get(i).getByXPath("td[3]").get(0)).asText();
                //Макс.
                data[i][3] = ((HtmlElement) items.get(i).getByXPath("td[4]").get(0)).asText();
                //Мин.
                data[i][4] = ((HtmlElement) items.get(i).getByXPath("td[5]").get(0)).asText();
                //Объем
                data[i][5] = ((HtmlElement) items.get(i).getByXPath("td[6]").get(0)).asText();
                //Изм.%
                data[i][6] = ((HtmlElement) items.get(i).getByXPath("td[7]").get(0)).asText();
            }
            return data;
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return null;
    }
}
