import java.util.ArrayList;

public class Main {
    public static ArrayList<Okrag> stworzOkregi(Okrag okrag1 ,Okrag okrag2){
        ArrayList<Okrag> okregi = new ArrayList<>();
        okregi.add(okrag1);
        okregi.add(okrag2);
        return okregi;
    }


    public static void main(String[] args) {
        Zad1 obj = new Zad1();
        System.out.println(obj);
        obj.zliczSumeWKolumnie();
        System.out.println("-------------ZAD 2----------------");

        Zad2 obj2 = new Zad2();
        System.out.println(obj2);
        obj2.zliczStosunek();

        System.out.println("-------------ZAD 3----------------");
        ArrayList<Okrag> okregi = stworzOkregi(new Okrag(0,0,3),new Okrag(7,0,3));
        for (Okrag o : okregi){
            System.out.println(o);
        }
        okregi.get(0).polozenieWzgledemOkregu(okregi.get(1));
    }
}