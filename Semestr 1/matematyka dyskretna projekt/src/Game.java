import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;

public class Game {
    private Integer numberOfRooms;
    private Integer numberOfKids;
    private ArrayList<Child> children;
    private ArrayList<String> moveSequence;
    private ArrayList<Room> rooms;
    private ArrayList<Integer> winningRooms;
    private ArrayList<GameState> gameHistory;

    public Game(Integer numberOfRooms, Integer numberOfKids, ArrayList<String> input) {
        this.numberOfRooms = numberOfRooms;
        this.numberOfKids = numberOfKids;
        this.children = new ArrayList<>();
        this.rooms = new ArrayList<>();
        this.winningRooms = new ArrayList<>();
        this.gameHistory = new ArrayList<>();
        inintialize(input);
    }

    public void inintialize(ArrayList<String> input){
        String[] startingRooms = input.get(2).split(" ");

        for (String startingRoom: startingRooms) {
            this.children.add(new Child(Integer.parseInt(startingRoom)));
        }
        this.saveGameState(0);
        this.winningRooms = Arrays.stream(input.get(3).split(" ")).map(Integer::parseInt).collect(Collectors.toCollection(ArrayList::new));;

        this.moveSequence = Arrays.stream(input.get(4).split("")).collect(Collectors.toCollection(ArrayList::new));;


        for(int i=5; i<numberOfRooms+5; i++){
            Integer[] doorsTarget = Arrays.stream(input.get(i).split(" "))
                    .map(Integer::parseInt)
                    .toArray(Integer[]::new);
            rooms.add(new Room(i-4,doorsTarget));
        }
    }

    public void saveGameState(Integer sequenceIndex){
        ArrayList<Integer> row = new ArrayList<>();
        for (Child child: children) {
            row.add(child.getRoom());
        }
        row.sort(Integer::compareTo);
        GameState gameState = new GameState(sequenceIndex, row);
        this.gameHistory.add(gameState);
    }

    public void moveChildToNextRoom(Child child,Integer sequenceIndex){
        Integer childRoomIndex = child.getRoom()-1;
        Room childRoom = rooms.get(childRoomIndex);
        Integer nextRoomIndex = childRoom.getDoorsTarget(moveSequence.get(sequenceIndex));
        child.goToRoom(nextRoomIndex);
    }

    public Boolean isGameLoopingItself(Integer currentSequenceIndex){
        ArrayList<Integer> childrenCurrentRooms = new ArrayList<>();
        for (Child child:children){
            childrenCurrentRooms.add(child.getRoom());
        }
        childrenCurrentRooms.sort(Integer::compareTo);

        for (GameState gameState : gameHistory){
            if (gameState.getOccupiedRooms().equals(childrenCurrentRooms) && currentSequenceIndex == gameState.getSequenceIndex()){
                return true;
            }
        }
        return false;
    }

    public Boolean allChildrenInWinningRooms(){
        for (Child child : children) {
            if (!winningRooms.contains(child.getRoom())) {
                return false;
            }
        }
        return true;
    }

    public void printGameState(Integer sequenceIndex){
        StringBuilder sb = new StringBuilder();

        for (int i=0;i<numberOfKids;i++){
            sb.append("Dz[" + i + "]:"+children.get(i).getRoom() + "   ");
        }
        sb.append(moveSequence.get(sequenceIndex));
        sb.append("\n");
        System.out.println(sb.toString());
    }

    public ArrayList<Child> getChildren() {
        return children;
    }

    public ArrayList<String> getMoveSequence() {
        return moveSequence;
    }


}
