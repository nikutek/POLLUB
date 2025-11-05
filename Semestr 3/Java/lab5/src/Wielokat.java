class Wielokat {
    private int liczbaWierzcholkow;
    private int liczbaBokow;
    private double sumaKatowWewnetrznych;


    public Wielokat(int liczbaWierzcholkow, int liczbaBokow, int sumaKatowWewnetrznych) {
        this.liczbaWierzcholkow = liczbaWierzcholkow;
        this.liczbaBokow = liczbaBokow;
        this.sumaKatowWewnetrznych = (liczbaBokow - 2) * 180;
    }

    public Wielokat(int liczbaWierzcholkow) {
        this.liczbaWierzcholkow = liczbaWierzcholkow;
    }

    public int getLiczbaWierzcholkow() {
        return liczbaWierzcholkow;
    }

    public void setLiczbaWierzcholkow(int liczbaWierzcholkow) {
        this.liczbaWierzcholkow = liczbaWierzcholkow;
    }

    public int getLiczbaBokow() {
        return liczbaBokow;
    }

    public void setLiczbaBokow(int liczbaBokow) {
        this.liczbaBokow = liczbaBokow;
    }

    public int getSumaKatowWewnetrznych() {
        return sumaKatowWewnetrznych;
    }

    public void setSumaKatowWewnetrznych(int sumaKatowWewnetrznych) {
        this.sumaKatowWewnetrznych = sumaKatowWewnetrznych;
    }
}
