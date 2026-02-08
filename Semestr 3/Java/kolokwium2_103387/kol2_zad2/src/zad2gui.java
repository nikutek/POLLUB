import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;

public class zad2gui extends JFrame {
    private JPanel mainPanel;
    private JLabel polozenieLabel;

    public zad2gui() {
        setContentPane(mainPanel);
        setTitle("zad2");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        mainPanel.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                Point p = e.getLocationOnScreen();
                polozenieLabel.setText("X=" + p.x + ", Y=" + p.y);
            }
        });

        mainPanel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                System.out.println("Mysz weszła");
                mainPanel.setBackground(Color.GREEN);
            }

            @Override
            public void mouseExited(MouseEvent e) {
                System.out.println("Mysz wyszła");
                mainPanel.setBackground(Color.RED);
            }
        });
    }
}