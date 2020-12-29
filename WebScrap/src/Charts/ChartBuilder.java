/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Charts;

import org.jfree.data.time.*;
import org.jfree.data.xy.XYDataset;
import org.jfree.chart.plot.*;
import org.jfree.chart.*;
import org.jfree.chart.renderer.xy.*;
import org.jfree.chart.axis.DateAxis;
import org.jfree.ui.RectangleInsets;
import java.awt.Color;
import java.text.SimpleDateFormat;
import java.text.DecimalFormat;
import java.util.Locale;
import java.util.Date;
import java.text.DateFormatSymbols;

/**
 *
 * @author AntKerf
 */
public class ChartBuilder {

    public static JFreeChart createChart(String Name, Object[][] data) {
        XYDataset dataset = _datasetBuilder(Name, data);
        JFreeChart chart = ChartFactory.createTimeSeriesChart(
                "График акций " + Name, // title
                "", // x-axis label
                "Стоимость", // y-axis label
                dataset, // data
                true, // create legend
                true, // generate tooltips
                false // generate URLs
        );
        chart.setBackgroundPaint(Color.white);

        XYPlot plot = (XYPlot) chart.getPlot();
        plot.setBackgroundPaint(Color.lightGray);
        plot.setDomainGridlinePaint(Color.white);
        plot.setRangeGridlinePaint(Color.white);
        plot.setAxisOffset(new RectangleInsets(5.0, 5.0, 5.0, 5.0));
        plot.setDomainCrosshairVisible(true);
        plot.setRangeCrosshairVisible(true);

        XYItemRenderer r = plot.getRenderer();
        if (r instanceof XYLineAndShapeRenderer) {
            XYLineAndShapeRenderer renderer = (XYLineAndShapeRenderer) r;
            renderer.setBaseShapesVisible(true);
            renderer.setBaseShapesFilled(true);
            renderer.setDrawSeriesLineAsPath(true);
        }

        DateAxis axis = (DateAxis) plot.getDomainAxis();
        axis.setDateFormatOverride(new SimpleDateFormat("dd.MM.YY"));
        return chart;
    }

    private static XYDataset _datasetBuilder(String Name, Object[][] data) {
        try {
            TimeSeries s1 = new TimeSeries(Name);
            SimpleDateFormat format = new SimpleDateFormat("dd.MM.yyyy");
            format.setLenient(false);
            Date parsedDate = null;
            try {
                parsedDate = format.parse(data[0][0].toString());
            } catch (Exception e) {
            }
            if (parsedDate != null) {
                for (var el : data) {
                    String[] date = el[0].toString().split("\\.");
                    int day = Integer.parseInt(date[0]);
                    int month = Integer.parseInt(date[1]);
                    int year = Integer.parseInt(date[2]);
                    Double value = DecimalFormat.getNumberInstance(Locale.GERMAN).parse(el[1].toString()).doubleValue();
                    s1.add(new Day(day, month, year), value);
                }
            } else { // если формат даты == "Дек. '20"
                for (var el : data) {
                    String[] date = el[0].toString().split("\\'");
                    String[] RuShortMonths = {"Янв. ", "Февр. ", "Март ", "Апр. ", "Май ", "Июнь ", "Июль ", "Авг. ", "Сент. ", "Окт. ", "Нояб. ", "Дек. "};
                    String Month = date[0];
                    String year = date[1];
                    Double value = DecimalFormat.getNumberInstance(Locale.GERMAN).parse(el[1].toString()).doubleValue();
                    for (int i = 0; i < RuShortMonths.length; i++) {
                        if (RuShortMonths[i].equals(Month)) {
                            s1.add(new Month(i + 1, Integer.parseInt(year)), value);
                        }
                    }
                }
            }
            TimeSeriesCollection dataset = new TimeSeriesCollection();
            dataset.addSeries(s1);
            return dataset;
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        return null;
    }

    public static javax.swing.JPanel createPanel(String name, Object[][] data) {
        JFreeChart chart = createChart(name, data);
        chart.setPadding(new RectangleInsets(4, 8, 2, 2));
        ChartPanel panel = new ChartPanel(chart);
        panel.setFillZoomRectangle(true);
        panel.setMouseWheelEnabled(true);
        panel.setPreferredSize(new java.awt.Dimension(300, 300));
        return panel;
    }
}
