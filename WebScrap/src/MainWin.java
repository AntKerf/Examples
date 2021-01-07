/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author AntKerf
 */
import webscrap.WebScrap;
import webscrap.MyUtil.*;
import Charts.ChartBuilder;
import com.github.lgooddatepicker.components.DatePicker;
import com.github.lgooddatepicker.components.DatePickerSettings;
import java.time.LocalDate;

public class MainWin extends javax.swing.JFrame {

    /**
     * Creates new form MainWin
     */
    public MainWin() {
        try {
            WebScrap._init();
            initComponents();
        } catch (Exception ex) {
            System.exit(1);//аварийное завершение при ошибке инициализации
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jFrame1 = new javax.swing.JFrame();
        jTabbedPane1 = new javax.swing.JTabbedPane();
        jPanel1 = new javax.swing.JPanel();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jPanel2 = new javax.swing.JPanel();
        AccesButton = new javax.swing.JButton();
        end_data = new javax.swing.JFormattedTextField();
        PeriodComboBox = new javax.swing.JComboBox<>();
        st_Date = new javax.swing.JFormattedTextField();
        jCtockComboBox = new javax.swing.JComboBox<>();
        jScrollPane1 = new javax.swing.JScrollPane();
        jEquitiesTable = new javax.swing.JTable();
        jMenuBar1 = new javax.swing.JMenuBar();
        FileMenu = new javax.swing.JMenu();
        ExitInMenu = new javax.swing.JMenuItem();
        ParamMenu = new javax.swing.JMenu();
        ReloadInMenu = new javax.swing.JMenuItem();
        DesignInMenu = new javax.swing.JMenu();
        jMenuItem4 = new javax.swing.JMenuItem();
        jMenuItem5 = new javax.swing.JMenuItem();
        jMenuItem2 = new javax.swing.JMenuItem();

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Title 1", "Title 2", "Title 3", "Title 4"
            }
        ));
        jScrollPane2.setViewportView(jTable1);

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jScrollPane2, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 383, Short.MAX_VALUE)
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 233, Short.MAX_VALUE)
        );

        jTabbedPane1.addTab("Table", jPanel1);

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 383, Short.MAX_VALUE)
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 233, Short.MAX_VALUE)
        );

        jTabbedPane1.addTab("Graph", jPanel2);

        AccesButton.setText("Применить");

        end_data.setText("22/11/2020");

        PeriodComboBox.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Item 1", "Item 2", "Item 3", "Item 4" }));

        st_Date.setText("22/12/2020");

        javax.swing.GroupLayout jFrame1Layout = new javax.swing.GroupLayout(jFrame1.getContentPane());
        jFrame1.getContentPane().setLayout(jFrame1Layout);
        jFrame1Layout.setHorizontalGroup(
            jFrame1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTabbedPane1, javax.swing.GroupLayout.Alignment.TRAILING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jFrame1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(PeriodComboBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(st_Date, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(end_data, javax.swing.GroupLayout.PREFERRED_SIZE, 73, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(AccesButton)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jFrame1Layout.setVerticalGroup(
            jFrame1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jFrame1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jFrame1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(AccesButton)
                    .addComponent(end_data, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(PeriodComboBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(st_Date, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jTabbedPane1))
        );

        jTabbedPane1.getAccessibleContext().setAccessibleName("Таблица");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("WebScrap");
        setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));

        jCtockComboBox.setModel(new javax.swing.DefaultComboBoxModel<>(WebScrap._stocks()));
        jCtockComboBox.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                jCtockComboBoxItemStateChanged(evt);
            }
        });

        jEquitiesTable.setModel(new javax.swing.table.DefaultTableModel(
            WebScrap._data(),
            new String [] {
                "Название", "Цена", "Макс.", "Мин.", "Изм.", "Изм.%", "Объем", "Время"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false, false, false, false,
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jEquitiesTable.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jEquitiesTableMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(jEquitiesTable);

        FileMenu.setText("Файл");

        ExitInMenu.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_E, java.awt.event.InputEvent.SHIFT_DOWN_MASK | java.awt.event.InputEvent.CTRL_DOWN_MASK));
        ExitInMenu.setText("Выход");
        ExitInMenu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ExitInMenuActionPerformed(evt);
            }
        });
        FileMenu.add(ExitInMenu);

        jMenuBar1.add(FileMenu);

        ParamMenu.setText("Параметры");

        ReloadInMenu.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_R, java.awt.event.InputEvent.CTRL_DOWN_MASK));
        ReloadInMenu.setText("Обновить");
        ReloadInMenu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ReloadInMenuActionPerformed(evt);
            }
        });
        ParamMenu.add(ReloadInMenu);

        DesignInMenu.setText("Дизайн");

        jMenuItem4.setText("Nimbus");
        DesignInMenu.add(jMenuItem4);

        jMenuItem5.setText("Windows");
        DesignInMenu.add(jMenuItem5);

        ParamMenu.add(DesignInMenu);

        jMenuItem2.setText("Шрифт");
        ParamMenu.add(jMenuItem2);

        jMenuBar1.add(ParamMenu);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jCtockComboBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jCtockComboBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 635, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jCtockComboBoxItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_jCtockComboBoxItemStateChanged
        //загрузка страницы с данными выбраной биржи
        WebScrap._loadStock(jCtockComboBox.getSelectedIndex());
        //установка котировок с загруженной страницы в таблицу
        jEquitiesTable.setModel(new javax.swing.table.DefaultTableModel(
                WebScrap._data(),
                new String[]{
                    "Название", "Цена", "Макс.", "Мин.", "Изм.", "Изм.%", "Объем", "Время"
                }));
    }//GEN-LAST:event_jCtockComboBoxItemStateChanged

    private void jEquitiesTableMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jEquitiesTableMouseClicked
        int row = jEquitiesTable.rowAtPoint(evt.getPoint());
        _FormEquitie(row);
    }//GEN-LAST:event_jEquitiesTableMouseClicked

    private void ExitInMenuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ExitInMenuActionPerformed
        System.exit(0);
    }//GEN-LAST:event_ExitInMenuActionPerformed

    private void ReloadInMenuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ReloadInMenuActionPerformed
        //загрузка страницы с данными выбраной биржи
        WebScrap._loadStock(jCtockComboBox.getSelectedIndex());
        //установка котировок с загруженной страницы в таблицу
        jEquitiesTable.setModel(new javax.swing.table.DefaultTableModel(
                WebScrap._data(),
                new String[]{
                    "Название", "Цена", "Макс.", "Мин.", "Изм.", "Изм.%", "Объем", "Время"
                }));
    }//GEN-LAST:event_ReloadInMenuActionPerformed

    //создание окна с подробной информацией по выбранной акции
    private void _FormEquitie(int row) {
        //окно
        javax.swing.JFrame tmp = new javax.swing.JFrame();
        tmp.setTitle("Установка соединения...");
        tmp.setSize(new java.awt.Dimension(400, 400));
        tmp.setLocation(500, 100);
        tmp.setDefaultCloseOperation(javax.swing.JFrame.HIDE_ON_CLOSE);
        //показ окна
        tmp.setLocationRelativeTo(null);
        tmp.setVisible(true);

        try {

            /*      Object [][] HistData= EquitieData.getFirst(); //таблица с данными
        int pairId = EquitieData.getSecond()[0];    
        int smlId = EquitieData.getSecond()[1];*/
            //получение данных по акции
            Pair<Object[][], Integer[]> EquitieData = new Pair<>(WebScrap._GetHistoryEquitie(row));
            tmp.setTitle(jEquitiesTable.getValueAt(row, 0).toString());
            //кнопки и текст. поля - управление
            var AccesButton = new javax.swing.JButton();
            var PeriodComboBox = new javax.swing.JComboBox<>();

            //вкладки
            var jTab = new javax.swing.JTabbedPane();
            var jTablePanel = new javax.swing.JPanel();//вкладка с таблицей

            javax.swing.JScrollPane jScrPane = new javax.swing.JScrollPane();
            javax.swing.JTable jHistTable = new javax.swing.JTable();//таблица
            jScrPane.setVerticalScrollBarPolicy(javax.swing.JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

            //заполнение таблицы
            jHistTable.setModel(new javax.swing.table.DefaultTableModel(
                    EquitieData.getFirst(), //получение данных
                    new String[]{
                        "Дата", "Цена", "Откр.", "Макс.", "Мин.", "Объем", "Изм.%"
                    }
            ));
            jScrPane.setViewportView(jHistTable);//привязка таблицы к прокрутке
            javax.swing.GroupLayout jTableLayout = new javax.swing.GroupLayout(jTablePanel);//выравнивание по вкладке
            jTablePanel.setLayout(jTableLayout);
            jTableLayout.setHorizontalGroup(
                    jTableLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jScrPane, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 395, Short.MAX_VALUE)
            );
            jTableLayout.setVerticalGroup(
                    jTableLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jScrPane, javax.swing.GroupLayout.DEFAULT_SIZE, 272, Short.MAX_VALUE)
            );
            jTab.add("Таблица", jTablePanel);//привязка панели с прокруткой и таблиецй к вкладке
            //рисование графика
            jTab.add("График", ChartBuilder.createPanel(tmp.getTitle(), EquitieData.getFirst()));//приязка графика к вкладке
            //настройка элементов управления
            DatePickerSettings dateSettings = new DatePickerSettings();
            dateSettings.setFormatForDatesCommonEra("dd/MM/yyyy");
            dateSettings.setFormatForDatesBeforeCommonEra("dd/MM/uuuu");

            DatePickerSettings dateSettings1 = new DatePickerSettings();
            dateSettings1.setFormatForDatesCommonEra("dd/MM/yyyy");
            dateSettings1.setFormatForDatesBeforeCommonEra("dd/MM/uuuu");

            DatePicker st_date = new DatePicker(dateSettings);
            DatePicker end_date = new DatePicker(dateSettings1);
            end_date.setDateToToday();
            st_date.setDate(LocalDate.now().minusMonths(1));
            PeriodComboBox.setModel(new javax.swing.DefaultComboBoxModel<>(new String[]{"Daily", "Weekly", "Monthly"}));

            AccesButton.setText("Применить");
            AccesButton.addActionListener(new java.awt.event.ActionListener() {
                public void actionPerformed(java.awt.event.ActionEvent evt) {
                    Object[][] newData = WebScrap._postReq(EquitieData.getSecond()[0], EquitieData.getSecond()[1], st_date.getText(), end_date.getText(), PeriodComboBox.getModel().getSelectedItem().toString());
                    jHistTable.setModel(new javax.swing.table.DefaultTableModel(
                            newData,
                            new String[]{
                                "Дата", "Цена", "Откр.", "Макс.", "Мин.", "Объем", "Изм.%"
                            }
                    ));
                    jTab.setComponentAt(1, ChartBuilder.createPanel(tmp.getTitle(), newData));
                }
            });
            //выравнивание вкладок с окном
            javax.swing.GroupLayout jFrameLayout = new javax.swing.GroupLayout(tmp.getContentPane());
            tmp.getContentPane().setLayout(jFrameLayout);
            jFrameLayout.setHorizontalGroup(
                    jFrameLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jTab, javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jFrameLayout.createSequentialGroup()
                                    .addContainerGap()
                                    .addComponent(PeriodComboBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(st_date, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(end_date, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(AccesButton)
                                    .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            );
            jFrameLayout.setVerticalGroup(
                    jFrameLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jFrameLayout.createSequentialGroup()
                                    .addContainerGap()
                                    .addGroup(jFrameLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                            .addComponent(AccesButton)
                                            .addComponent(end_date, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(PeriodComboBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(st_date, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(jTab))
            );

            tmp.pack();
        } catch (Exception ex) {
            ErrorFrame errorFrame = new ErrorFrame(ex);
            tmp.dispose();
        }
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MainWin.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        //Create & display Splash Screen
        SplashScreen Splash = new SplashScreen();
        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            new MainWin().setVisible(true);
        });
        //dispose splash screen after mainForm display
        Splash.dispose();

    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton AccesButton;
    private javax.swing.JMenu DesignInMenu;
    private javax.swing.JMenuItem ExitInMenu;
    private javax.swing.JMenu FileMenu;
    private javax.swing.JMenu ParamMenu;
    private javax.swing.JComboBox<String> PeriodComboBox;
    private javax.swing.JMenuItem ReloadInMenu;
    private javax.swing.JFormattedTextField end_data;
    private javax.swing.JComboBox<String> jCtockComboBox;
    private javax.swing.JTable jEquitiesTable;
    private javax.swing.JFrame jFrame1;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem2;
    private javax.swing.JMenuItem jMenuItem4;
    private javax.swing.JMenuItem jMenuItem5;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTabbedPane jTabbedPane1;
    private javax.swing.JTable jTable1;
    private javax.swing.JFormattedTextField st_Date;
    // End of variables declaration//GEN-END:variables

}
