public class Child {

    private Integer room;
    public Child(Integer room) {
        this.room = room;
    }
    public Integer getRoom() {
        return room;
    }
    public void goToRoom(Integer room) {
        this.room = room;
    }
    public String toString() {
        return "Child in" + room; // lub inne właściwości dziecka
    }
}
