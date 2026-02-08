import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        LinkedList<Statek> statki = new LinkedList<>();


        statki.add(new Statek("statek", true, 10));
        statki.add(new Statek("Heweliusz", false, 5));
        statki.add(new Statek("Heweliusz", false, 20)); // Ten powinien być przed Batory (5)
        statki.add(new Statek("statek", true, 50)); // Ten powinien być przed Ametyst (10)

        System.out.println("Przed sortowaniem: ");
        for (Statek statek : statki){
            System.out.println(statek);
        }

        Collections.sort(statki,
                Comparator
                        .comparing(Statek::getNazwa)
                        .thenComparing(Comparator.comparing(Statek::getIloscUzbrojenia).reversed())
        );

        System.out.println("Po sortowaniu: ");
        for (Statek statek : statki){
            System.out.println(statek);
        }
    }
}