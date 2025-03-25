import java.util.Arrays;

public class Room {
    private Integer roomNumber;
    private Integer[] doorsTarget;
    public Room(Integer roomNumber, Integer[] doorsTarget) {
        this.roomNumber = roomNumber;
        this.doorsTarget = doorsTarget;
    }

    public Integer getDoorsTarget(String doorLetter) {
        if (doorLetter.equals("A")){
            return doorsTarget[0];
        }else if (doorLetter.equals("B")){
            return doorsTarget[1];
        }
        else if (doorLetter.equals("C")){
            return doorsTarget[2];
        }
        else if (doorLetter.equals("D")) {
            return doorsTarget[3];
        }else{
            return -1;
        }
    }
    public String toString() {
        return "Room " + roomNumber+ " -> Doors Target: " + Arrays.toString(doorsTarget);
    }
}
