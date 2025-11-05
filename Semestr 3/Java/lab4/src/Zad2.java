import java.util.ArrayList;
import java.util.Random;

public class Zad2 {

    private ArrayList<ArrayList<Integer>> arr;
    private int sizeOfSquare;
    private Random rand;

    public Zad2(){
        this.rand = new Random();
        this.sizeOfSquare = rand.nextInt(11) +10;
        this.arr = new ArrayList<>();

        for (int i = 0; i < sizeOfSquare; i++){
            ArrayList<Integer> temp = new ArrayList<>();
            for (int j = 0; j < sizeOfSquare; j++) {
                if(i==j){
                    temp.add(rand.nextInt(2)-1);
                } else{
                    temp.add(rand.nextInt(41)-20);
                }
            }

            this.arr.add(temp);

        }
    }

    public void zliczStosunek(){
        int sumaWParzystychWierszach =0;
        int sumaWNieparzystychWierszach =0;

        for (int i=0; i<sizeOfSquare; i++){
            for (int j=0; j < sizeOfSquare; j++){
                if(i%2==0){
                    sumaWParzystychWierszach+= this.arr.get(i).get(j);
                } else {
                    sumaWNieparzystychWierszach+= this.arr.get(i).get(j);
                }
            }
        }
        System.out.println("suma w parzystych: " + sumaWParzystychWierszach);
        System.out.println("suma w nieparzystych: " + sumaWNieparzystychWierszach);
        System.out.println("stosunek parzystych do nieparzystych: " + 1.0*sumaWParzystychWierszach/sumaWNieparzystychWierszach);
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
