import java.util.ArrayList;

public class Zad1 {
    private ArrayList<ArrayList<String>> arr;

    public Zad1(){
        this.arr = new ArrayList<>();
        for (int i = 0; i < 10; i++){
            ArrayList<String> temp = new ArrayList<>();
            for (int j = i * 10; j < i * 10 + 10; j++) {
                String numWith0 = (j < 10) ? "0" + j : Integer.toString(j);
                temp.add(numWith0);
            }

            this.arr.add(temp);

        }
    }

    public void zliczSumeWKolumnie(){
        for (int k=0; k<this.arr.size(); k++){
            int sumaWKolumnie = 0;
            for (int w=0 ;w < this.arr.get(0).size(); w++){
                int liczba = Integer.valueOf(this.arr.get(w).get(k));
                sumaWKolumnie += liczba;
            }
            System.out.print(sumaWKolumnie + " ");
        }
        System.out.println("");
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for  (int i = 0; i < this.arr.size(); i++){
            for (int j = 0; j < this.arr.get(i).size(); j++){
                sb.append(this.arr.get(i).get(j));
                sb.append(", ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }

}
