public class Figura extends Wielokat{
    protected int pole;
    protected int obwod;
    private Kolor kolor;

    public Figura(int pole, int obwod, Kolor kolor) {
        this.pole = pole;
        this.obwod = obwod;
        this.kolor = kolor;
    }

    public Figura() {
    }

    public int getPole() {
        return pole;
    }

    public void setPole(int pole) {
        this.pole = pole;
    }

    public int getObwod() {
        return obwod;
    }

    public void setObwod(int obwod) {
        this.obwod = obwod;
    }

    public Kolor getKolor() {
        return kolor;
    }

    public void setKolor(Kolor kolor) {
        this.kolor = kolor;
    }
}
