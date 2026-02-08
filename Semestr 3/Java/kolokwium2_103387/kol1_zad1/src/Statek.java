public class Statek {
    private String nazwa;
    private boolean stan;
    private int iloscUzbrojenia;

    public Statek(String nazwa, boolean stan, int iloscUzbrojenia) {
        this.nazwa = nazwa;
        this.iloscUzbrojenia = iloscUzbrojenia;
    }

    public String getNazwa() {
        return nazwa;
    }

    public void setNazwa(String nazwa) {
        this.nazwa = nazwa;
    }

    public void setIloscUzbrojenia(int iloscUzbrojenia) {
        this.iloscUzbrojenia = iloscUzbrojenia;
    }

    public int getIloscUzbrojenia() {
        return iloscUzbrojenia;
    }

    @Override
    public String toString() {
        return nazwa + ';' + iloscUzbrojenia +";";
    }


}
