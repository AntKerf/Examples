import com.formdev.flatlaf.FlatDarkLaf;
import com.formdev.flatlaf.FlatLightLaf;
import java.awt.Font;
import java.io.File;
import java.io.IOException;
import javax.swing.UIManager;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

//Класс для управления загрузкой/сохранением кофигурации UIManager

/**
 * @author Ant_Kerf
 */
public class UIConfigController {

    public static void loadUIConfig() {
        try {
            // Создается построитель документа
            DocumentBuilder documentBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
            // Создается дерево DOM документа из файла
            org.w3c.dom.Document document = documentBuilder.parse("Config.xml");
            // Получаем корневой элемент
            Node root = document.getDocumentElement();
            // Просматриваем все подэлементы корневого
            NodeList Settings = root.getChildNodes();
            //default
            String FontName = "Tahoma";
            Integer FontSize = 11;
            int FontStyle = 0;
            //чтение параметров из файла
            for (int i = 0; i < Settings.getLength(); i++) {
                Node Param = Settings.item(i);
                if (Param.getNodeType() != Node.TEXT_NODE) {
                    switch (Param.getNodeName()) {
                        case "Theme" -> //установка темы из конфига
                            setUITheme(Param.getChildNodes().item(0).getTextContent());
                        case "TextStyle" -> {
                            switch (Param.getChildNodes().item(0).getTextContent()) {
                                case "0" ->
                                    FontStyle = Font.PLAIN;
                                case "1" ->
                                    FontStyle = Font.BOLD;
                                case "2" ->
                                    FontStyle = Font.ITALIC;
                            }
                        }
                        case "Font" ->
                            FontName = Param.getChildNodes().item(0).getTextContent();
                        case "FontSize" ->
                            FontSize = Integer.parseInt(Param.getChildNodes().item(0).getTextContent());
                        default -> {
                            break;
                        }
                    }
                }
            }
            setUIFont(new javax.swing.plaf.FontUIResource(new Font(FontName, FontStyle, FontSize)));
        } catch (ParserConfigurationException | SAXException | IOException ex) {
            ex.printStackTrace(System.out);
        }
    }

    public static void saveUIConfig() {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder;
        try {
            builder = factory.newDocumentBuilder();

            // создаем пустой объект Document, в котором будем 
            // создавать наш xml-файл
            Document doc = builder.newDocument();

            doc.appendChild(getUIConfig(doc));

            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            // для переноса параметров на новую строку
            transformer.setOutputProperty(OutputKeys.INDENT, "yes");
            DOMSource source = new DOMSource(doc);

            StreamResult file = new StreamResult(new File("Config.xml"));

            //записываем данные
            transformer.transform(source, file);
            System.out.println("Создание XML файла закончено");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static Node getUIConfig(Document doc) {
        Element root = doc.createElement("Config");

        Element theme = doc.createElement("Theme");
        theme.appendChild(doc.createTextNode(UIManager.getLookAndFeel().getName()));
        root.appendChild(theme);

        Element textStyle = doc.createElement("TextStyle");
        textStyle.appendChild(doc.createTextNode(String.valueOf(UIManager.getFont("TextField.font").getStyle())));
        root.appendChild(textStyle);

        Element font = doc.createElement("Font");
        font.appendChild(doc.createTextNode(UIManager.getFont("TextField.font").getName()));
        root.appendChild(font);

        Element fontSize = doc.createElement("FontSize");
        fontSize.appendChild(doc.createTextNode(String.valueOf(UIManager.getFont("TextField.font").getSize())));
        root.appendChild(fontSize);
        return root;
    }

    //установка шрифта для всех элементов (шрифт,стиль,размер)
    public static void setUIFont(javax.swing.plaf.FontUIResource f) {
        java.util.Enumeration<Object> keys = UIManager.getDefaults().keys();
        while (keys.hasMoreElements()) {
            Object key = keys.nextElement();
            Object value = UIManager.get(key);
            if (value instanceof javax.swing.plaf.FontUIResource) {
                UIManager.put(key, f);
            }
        }
    }

    public static void setUITheme(String ThemeName) {
        try {
            switch (ThemeName) {
                case "Flat Dark" ->
                    UIManager.setLookAndFeel(new FlatDarkLaf());
                case "Flat Light" ->
                    UIManager.setLookAndFeel(new FlatLightLaf());
                default -> {
                    for (UIManager.LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                        if (ThemeName.equals(info.getName())) {
                            UIManager.setLookAndFeel(info.getClassName());
                            break;
                        }
                    }
                }
            }
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MainWin.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
    }
}
