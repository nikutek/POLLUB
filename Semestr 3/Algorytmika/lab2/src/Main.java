import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static int factorial(int n) {
        int fact = 1;
        for (int i = 2; i <= n; i++) {
            fact = fact * i;
        }
        return fact;
    }

    public static ArrayList<Integer> policzWyniki(ArrayList<Integer> wspolczynniki, Integer punkt) {
        Integer stopien = wspolczynniki.size() - 1;
        ArrayList<Integer> wyniki = new ArrayList<>();
        wyniki.add(wspolczynniki.get(0));
        for (int i = 1; i <= stopien; i++) {
            int ostatni = wyniki.get(i - 1);
            int wynik = wspolczynniki.get(i) + ostatni * punkt;
            wyniki.add(wynik);
        }
        return wyniki;
    }

    public static void main(String[] args) {
        int punkt = 2;
        int stopien = 4;
        ArrayList<Integer> wspolczynniki = new ArrayList<>(Arrays.asList(-3,0,1,-2,4));


        // OBLICZENIA

        ArrayList<Integer> pochodne = new ArrayList<>();
        ArrayList<Integer> wyniki = policzWyniki(wspolczynniki, punkt);
        while (wyniki.size() > 1) {
            pochodne.add(wyniki.getLast());
            wyniki.removeLast();
            wyniki = policzWyniki(wyniki, punkt);
        }
        pochodne.add(wyniki.get(0));
        wyniki.removeLast();

        for (Integer p : pochodne) {
            wyniki.add(p);
        }

        for (int i=0; i<=stopien; i++) {
            System.out.println("w(2)="+pochodne.get(i));
            System.out.println("w<"+i+">(2)="+ (wyniki.get(i)*factorial(i)));
        }
    }
}