class Eipsa extends Figura {
    private int a;
    private int b;
    private int x;
    private int y;
    private int f1x;
    private int f1y;
    private int f2x;
    private int f2y;
    private double c;

    public Eipsa(int pole, int obwod, Kolor kolor, int a, int b, int x, int y, int f1x, int f1y, int f2x, int f2y, int c) {
        super(pole, obwod, kolor);
        this.a = a;
        this.b = b;
        this.x = x;
        this.y = y;
        this.f1x = f1x;
        this.f1y = f1y;
        this.f2x = f2x;
        this.f2y = f2y;
        this.c = Math.sqrt(a*a - b*b);
    }

    public Eipsa() {}

    public int getA() {
        return a;
    }

    public void setA(int a) {
        this.a = a;
    }

    public int getB() {
        return b;
    }

    public void setB(int b) {
        this.b = b;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getF1x() {
        return f1x;
    }

    public void setF1x(int f1x) {
        this.f1x = f1x;
    }

    public int getF1y() {
        return f1y;
    }

    public void setF1y(int f1y) {
        this.f1y = f1y;
    }

    public int getF2x() {
        return f2x;
    }

    public void setF2x(int f2x) {
        this.f2x = f2x;
    }

    public int getF2y() {
        return f2y;
    }

    public void setF2y(int f2y) {
        this.f2y = f2y;
    }

    public double getC() {
        return c;
    }

    public void setC(int c) {
        this.c = c;
    }
}
