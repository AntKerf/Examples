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


/**
 *
 * @author Windows
 */
public class ChartBuilder {

    public static JFreeChart createChart() {
        XYDataset dataset = _datasetbuild();
        JFreeChart chart = ChartFactory.createTimeSeriesChart(
                "Демо версия графика", // title
                "", // x-axis label
                "Валюта", // y-axis label
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
        axis.setDateFormatOverride(new SimpleDateFormat("MM.YYYY"));
        return chart;
    }

    private static XYDataset _datasetbuild() {
        TimeSeries s1 = new TimeSeries("Какой либо курс");

        s1.add(new Month(7, 2013), 142.9);
        s1.add(new Month(8, 2013), 138.7);
        s1.add(new Month(9, 2013), 137.3);
        s1.add(new Month(10, 2013), 143.9);
        s1.add(new Month(11, 2013), 139.8);
        s1.add(new Month(12, 2013), 137.0);
        s1.add(new Month(1, 2014), 132.8);
        s1.add(new Month(2, 2014), 181.8);
        s1.add(new Month(3, 2014), 167.3);
        s1.add(new Month(4, 2014), 153.8);
        s1.add(new Month(5, 2014), 167.6);
        s1.add(new Month(6, 2014), 158.8);
        s1.add(new Month(7, 2014), 148.3);
        s1.add(new Month(8, 2014), 153.9);
        s1.add(new Month(9, 2014), 142.7);
        s1.add(new Month(10, 2014), 123.2);
        s1.add(new Month(11, 2014), 131.8);
        s1.add(new Month(12, 2014), 139.6);

        TimeSeriesCollection dataset = new TimeSeriesCollection();
        dataset.addSeries(s1);
        return dataset;
    }
        public static javax.swing.JPanel createDemoPanel() {
        JFreeChart chart = createChart();
        chart.setPadding(new RectangleInsets(4, 8, 2, 2));
        ChartPanel panel = new ChartPanel(chart);
        panel.setFillZoomRectangle(true);
        panel.setMouseWheelEnabled(true);
        panel.setPreferredSize(new java.awt.Dimension(300, 300));
        return panel;
    }
}
