public class Uzbrojenie {
    private String rodzajUzbrojenia;
    private int iloscUzbrojenia;

    public Uzbrojenie(String rodzajUzbrojenia, int iloscUzbrojenia) {
        this.rodzajUzbrojenia = rodzajUzbrojenia;
        this.iloscUzbrojenia = iloscUzbrojenia;
    }

    @Override
    public String toString() {
        return "Uzbrojenia{" +
                "rodzajUzbrojenia='" + rodzajUzbrojenia + '\'' +
                ", iloscUzbrojenia=" + iloscUzbrojenia +
                '}';
    }
}
