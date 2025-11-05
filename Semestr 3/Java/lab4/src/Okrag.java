public class Okrag {
    private double x;
    private double y;
    private double r;

    public Okrag(double x, double y, double r) {
        this.x = x;
        this.y = y;
        this.r = r;
    }

    public void polozenieWzgledemOkregu(Okrag inny){
        double odleglosc = Math.sqrt(Math.pow(inny.x - this.x, 2) + Math.pow(inny.y - this.y, 2));
        double sumaPromieni =this.r + inny.r;
        if(odleglosc < sumaPromieni){
            System.out.println("Okregi sie przecinaja");
        } else if (odleglosc == this.r + inny.r){
            System.out.println("Okregi sa styczne");
        } else {
            System.out.println("Okregi sie nie przecinaja");
        }
    }

    @Override
    public String toString() {
        return "Okrag{" +
                "x=" + x +
                ", y=" + y +
                ", r=" + r +
                '}';
    }
}
