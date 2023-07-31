class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class HelloWorld {
    private Node head;

    // Method to insert a new node at the beginning of the linked list
    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    // Method to display the elements of the linked list
    public void displayList() {
        Node current = head;
        System.out.print("Linked List: ");
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        SinglyLinkedList linkedList = new SinglyLinkedList();

        // Insert nodes at the beginning
        linkedList.insertAtBeginning(3);
        linkedList.insertAtBeginning(5);
        linkedList.insertAtBeginning(7);
        linkedList.insertAtBeginning(9);

        // Display the linked list
        linkedList.displayList();
    }
}
