/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package webscrap;

import java.util.List;

import com.gargoylesoftware.htmlunit.WebClient;
import com.gargoylesoftware.htmlunit.html.HtmlElement;
import com.gargoylesoftware.htmlunit.html.HtmlOption;
import com.gargoylesoftware.htmlunit.html.HtmlPage;
import com.gargoylesoftware.htmlunit.html.HtmlSelect;

/**
 *
 * @author Windows
 */
public class WebScrap {
//
//    public static void main(String[] args) {
//
//    }

    private static WebClient webClient;
    //основная страница
    private static HtmlPage mainPage;
    //страница с котировками по выбранной бирже
    private static HtmlPage stockPage;
    //номер биржи из списка на главной странице
    private static int currentIndexStock = 0;

    public static void _init() {
        System.out.println("Hello world! I`am a web  scrapper in future!");
        webClient = new WebClient();
        webClient.getOptions().setCssEnabled(false);
        webClient.getOptions().setJavaScriptEnabled(false);
        try {
            mainPage = webClient.getPage("https://ru.investing.com/equities/");
            stockPage = webClient.getPage("https://ru.investing.com/equities/StocksFilter?noconstruct=1&smlID=0&sid=&tabletype=price&index_id=13666");
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    //загрузка страницы с котировками выбранной биржы из списка
    public static void _loadStock(int index_stock) {
        if (index_stock != currentIndexStock) {
            try {
                //список всех бирж
                List<HtmlElement> items = mainPage.getByXPath("/html[1]/body[1]/div[5]/section[1]/div[6]/select[1]/option");
                //ид биржы по ее номеру в списке
                String stock_id = items.get(index_stock).getAttribute("id");
                //страница с котировками
                stockPage = webClient.getPage("https://ru.investing.com/equities/StocksFilter?noconstruct=1&smlID=0&sid=&tabletype=price&index_id="+stock_id);
                //установка выбранного номера биржы как текущий
                currentIndexStock = index_stock;
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }
    //загруза котировок со страницы выбранной биржи
    public static Object[][] _data() {
        Object[][] data;
        try {
            //получение строк из таблицы с котироками
            List<HtmlElement> items = stockPage.getByXPath("/html[1]/body[1]/div[1]/table[1]/tbody[1]/tr");
            data = new Object[items.size()][3];
            for (int i = 0; i < items.size(); i++) {
                //Название
                data[i][0] = ((HtmlElement)items.get(i).getByXPath("td[2]").get(0)).asText();
                //Цена
                data[i][1] = ((HtmlElement)items.get(i).getByXPath("td[3]").get(0)).asText();
                //Макс
                data[i][2] = ((HtmlElement)items.get(i).getByXPath("td[4]").get(0)).asText();
            }
            //возращаем массив с данными для вставки в таблицу
            return data;
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        //при ошибке ничего не возращаем
        return null;
    }
    //загрузка названий бирж
    public static String[] _stocks() {
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
}
