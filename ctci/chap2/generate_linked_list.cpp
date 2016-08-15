// This file has 2 classes.
// First class is a node. Second class is a generator of linked list.
#include <iostream>
using namespace std;

class Node {
    public:
        Node(int d) {
            data = d;
        }
    private:
        Node next = null;
        int d;
};

class LinkedListGenerator {
    public:
        LinkedListGenerator() {
            head = Node.new(1); // Give 1 for practice.
        }

        Node generateLinkedList(int length) {
            Node tmp = head;
            int data = 0;
            for (int i = 0; i < length - 1 ; i++) {
                tmp.next = Node.new(data++);
            }
            return head;
        }
    private:
        Node head = null;
};

// For testing
int main() {
    LinkedListGenerator generator;
    Node head = generator.generateLinkedList(5);
    int counter = 0;
    while (head.next != null) {
        cout << counter + 1 << " st data: " << head.data << endl;
        head = head.next;
        counter++;
    }
    cout << "The length of linked list is " << counter + 1 << endl;
}
