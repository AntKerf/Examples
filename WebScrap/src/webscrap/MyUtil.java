package webscrap;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.Font;
import javax.swing.ImageIcon;
import javax.swing.SwingConstants;

/**
 *
 * @author AntKerf
 */
public class MyUtil {

    // контейнер пара
    public static class Pair<F, S> {

        private F first;
        private S second;

        //Конструктор с параметрами 
        public Pair(F _first, S _second) {
            this.first = _first;
            this.second = _second;
        }

        //Конструктор копирования
        public Pair(Pair<F, S> toCopy) {
            this.first = toCopy.first;
            this.second = toCopy.second;
        }

        public F getFirst() {
            return this.first;
        }

        public S getSecond() {
            return this.second;
        }

        public void setFirst(F newFirst) {
            this.first = newFirst;
        }

        public void setSecond(S newSecond) {
            this.second = newSecond;
        }

    }

    public static class SplashScreen extends javax.swing.JWindow {

        public SplashScreen() {
            var image = new ImageIcon(getClass().getResource("/resources/logo.png"));
            javax.swing.JLabel label = new javax.swing.JLabel("", image, SwingConstants.CENTER);
            // getContentPane().add(label);
            setSize(300, 50);
            //setUndecorated(true);
            setBackground(new Color(1.0f, 1.0f, 1.0f, 0.0f));
            // Get current screen size
            Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
            // Get x coordinate on screen for make JWindow locate at center
            int x = (screenSize.width - getSize().width) / 2;
            // Get y coordinate on screen for make JWindow locate at center
            int y = (screenSize.height - getSize().height) / 2;
            // Set new location for JWindow
            setLocation(x, y);
            //выравнивание вкладок с окном
            javax.swing.GroupLayout jFrameLayout = new javax.swing.GroupLayout(getContentPane());
            getContentPane().setLayout(jFrameLayout);
            jFrameLayout.setHorizontalGroup(
                    jFrameLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(label, javax.swing.GroupLayout.Alignment.CENTER)
            );
            jFrameLayout.setVerticalGroup(
                    jFrameLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(label,javax.swing.GroupLayout.Alignment.LEADING)
            );

            // Make JWindow visible
            pack();
            setVisible(true);
        }
    }

    public static class ErrorFrame extends javax.swing.JDialog {

        public ErrorFrame(Exception ex) {
            javax.swing.JLabel label = new javax.swing.JLabel();
            this.setTitle("Ошибка! Попробуйте снова.");
            label.setText(ex.getMessage());
            add(label);
            setType(Type.POPUP);
            setModal(true);
            // Get current screen size
            Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
            // Get x coordinate on screen for make JWindow locate at center
            int x = (screenSize.width - getSize().width) / 2;
            // Get y coordinate on screen for make JWindow locate at center
            int y = (screenSize.height - getSize().height) / 2;
            // Set new location for JWindow
            setLocation(x, y);
            javax.swing.GroupLayout WaitFrameLayout = new javax.swing.GroupLayout(this.getContentPane());
            this.getContentPane()
                    .setLayout(WaitFrameLayout);
            WaitFrameLayout.setHorizontalGroup(
                    WaitFrameLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.CENTER)
                            .addComponent(label, javax.swing.GroupLayout.DEFAULT_SIZE, 150, Short.MAX_VALUE)
            );
            WaitFrameLayout.setVerticalGroup(
                    WaitFrameLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.CENTER)
                            .addComponent(label, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
            );
            pack();
            setLocationRelativeTo(null);
            // Make JWindow visible
            setVisible(true);
        }
    }
}
