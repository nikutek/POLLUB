//NIKODEM GOŁAWSKI 103387 grupa 3.2/4

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {


        USSConstitution ussc = new USSConstitution(true, "USSConstitution", 10);
        Statek statek = new Statek(false, "Statek", 40);
        ArrayList<Uzbrojenie> doZaladowania = new ArrayList<>();
        doZaladowania.add(new Uzbrojenie("Armata", 5));
        statek.zaladujUzbrojenia(doZaladowania);
        doZaladowania.add(new Uzbrojenie("Torpedata", 20));
        ussc.zaladujUzbrojenia((ArrayList<Uzbrojenie>) doZaladowania);

        System.out.println("Statek");
        System.out.println(statek.getUzbrojenia());
        System.out.println("USSC");
        System.out.println(ussc.getUzbrojenia());

    }


}