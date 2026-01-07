import javax.swing.*;

public class Index {
    private JPanel panel1;
    private JFormattedTextField liczba1FormattedTextField;
    private JFormattedTextField liczba2FormattedTextField;
    private JButton mnozenieButton;
    private JButton dodawanieButton;
    private JButton dzielenieButton;
    private JButton odejmowanieButton;
    private JTextPane WYNIKTextPane;

    public Index() {

        dodawanieButton.addActionListener(e -> oblicz("+"));
        odejmowanieButton.addActionListener(e -> oblicz("-"));
        mnozenieButton.addActionListener(e -> oblicz("*"));
        dzielenieButton.addActionListener(e -> oblicz("/"));
    }

    private void oblicz(String znak) {
        try {
            double a = Double.parseDouble(liczba1FormattedTextField.getText());
            double b = Double.parseDouble(liczba2FormattedTextField.getText());
            double wynik = 0;

            switch (znak) {
                case "+" -> wynik = a + b;
                case "-" -> wynik = a - b;
                case "*" -> wynik = a * b;
                case "/" -> {
                    if (b == 0) {
                        WYNIKTextPane.setText("Nie dziel przez zero");
                        return;
                    }
                    wynik = a / b;
                }
            }

            WYNIKTextPane.setText(String.valueOf(wynik));

        } catch (NumberFormatException ex) {
            WYNIKTextPane.setText("Błędne dane");
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Kalkulator");
        frame.setContentPane(new Index().panel1);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
