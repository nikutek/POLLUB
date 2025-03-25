import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        ArrayList<String> input = reader.getInput("./src/testy/test_03.in");
        Integer numberOfRooms = Integer.parseInt(input.get(0));
        Integer numberOfKids = Integer.parseInt(input.get(1));
        Game game = new Game(numberOfRooms,numberOfKids,input);


        Integer sequenceSize = game.getMoveSequence().size();
        Integer sequenceIndex = 0;
        Integer gameIndex = 0;

        long startTime = System.nanoTime();
        while (true){
            game.printGameState(sequenceIndex);
            if(game.allChildrenInWinningRooms()){
                System.out.println("Koniec po " + gameIndex + " iteracji");
                break;
            }

            for (Child child: game.getChildren()){
                game.moveChildToNextRoom(child,sequenceIndex);
            }

            if (game.isGameLoopingItself(sequenceIndex) && gameIndex>0){
                game.printGameState((sequenceIndex + 1) % sequenceSize);
                System.out.println("NIE");
                break;
            }

            game.saveGameState(sequenceIndex);
            sequenceIndex = (sequenceIndex +1)%sequenceSize;
            System.out.println(gameIndex);
            gameIndex++;
        }
        long endTime = System.nanoTime();
        long duration = endTime - startTime;
        System.out.println("Czas wykonania: " + (duration / 1_000_000) + " ms");
    }
}