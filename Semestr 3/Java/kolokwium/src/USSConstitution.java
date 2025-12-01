import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class USSConstitution extends Statek implements Uzbrojony{
    private List<Uzbrojenie> uzbrojenia;

    public USSConstitution(boolean czySprawny, String nazwa, int iloscPaliwa) {
        super(czySprawny, nazwa, iloscPaliwa);
        this.uzbrojenia = new ArrayList<>();
    }

    public void zaladujUzbrojenia(ArrayList<Uzbrojenie> uzbrojenia){
        for (Uzbrojenie uzb : uzbrojenia){
            this.uzbrojenia.add(uzb);
        }
    }

    public List<Uzbrojenie> getUzbrojenia() {
        return uzbrojenia;
    }

    public  List<Uzbrojenie> rozladujUzbrojenie(){
        List<Uzbrojenie> kopia = this.uzbrojenia.stream().collect(Collectors.toList());



        this.uzbrojenia.clear();
        return kopia;
    }


}
