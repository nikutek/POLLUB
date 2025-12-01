import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Statek implements Uzbrojony{
    private boolean czySprawny;
    protected String nazwa;
    protected int iloscPaliwa;
    private List<Uzbrojenie> uzbrojenia;


    public Statek(boolean czySprawny, String nazwa, int iloscPaliwa) {
        this.czySprawny = czySprawny;
        this.nazwa = nazwa;
        this.iloscPaliwa = iloscPaliwa;
        this.uzbrojenia = new ArrayList<>();
    }


    public void setCzySprawny(boolean stan) {
        this.czySprawny = stan;
    }

    public void dodajPaliwo(int paliwo){
        this.iloscPaliwa += paliwo;
    }

    public void naprawSie(){
        this.czySprawny = true;
    }

    public void walcz(){
        if(!this.czySprawny){
            System.out.println("Statek dokonuje napraw");
            naprawSie();
            return;
        }
        System.out.println("Statek walczy");
        this.czySprawny = false;
    }

    public List<Uzbrojenie> getUzbrojenia() {
        return uzbrojenia;
    }

    @Override
    public String toString() {
        return "Statek{" +
                "czySprawny=" + czySprawny +
                ", nazwa='" + nazwa + '\'' +
                ", iloscPaliwa=" + iloscPaliwa +
                '}';
    }

    public void zaladujUzbrojenia(ArrayList<Uzbrojenie> uzbrojenia){
        for (Uzbrojenie uzb : uzbrojenia){
            this.uzbrojenia.add(uzb);
        }
    }

    public  List<Uzbrojenie> rozladujUzbrojenie(){
        List<Uzbrojenie> kopia = this.uzbrojenia.stream().collect(Collectors.toList());
        this.uzbrojenia.clear();
        return kopia;
    }
}
