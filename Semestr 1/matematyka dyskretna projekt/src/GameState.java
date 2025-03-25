import java.util.ArrayList;

public class GameState {
    private Integer sequenceIndex;
    private ArrayList<Integer> occupiedRooms;
    public GameState(Integer sequenceIndex, ArrayList<Integer> occupiedRooms) {
        this.sequenceIndex = sequenceIndex;
        this.occupiedRooms = occupiedRooms;
    }
    public Integer getSequenceIndex() {
        return sequenceIndex;
    }
    public ArrayList<Integer> getOccupiedRooms() {
        return occupiedRooms;
    }
}
