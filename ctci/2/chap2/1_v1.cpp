#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
class Node {
    public: 
        Node (int v) : value(v) {};
        ~Node () {};
        Node* next = nullptr;
        int value;
        void append_to_tail(int v) {
            // Stuck here.
            // Before: Node new_n(v)
            //   This new_n will release the allocated memory after
            //   this function, leading to segmented fault.
            // After: new_n = new Node(v)
            //   new function first allocates memory for Node and then
            //   call the constructor. Thus even after this function,
            //   the allocated memory contains until delete function is
            //   explicitely called.
            Node* new_n = new Node(v);
            Node* n = this;
            while (n->next != nullptr) {
                n = n->next;
            }
            n->next = new_n;
        };
};

Node* remove_dups(Node* head) {
    unordered_map<int, bool> if_appeared;
    // Node& current = head
    //  resulted in giving just 2 (last element) after this function.
    // This is becasue current is the reference to the object head refereces to,
    // and if we update like:
    //  current = *(current.next)
    // The very object current references to "becomes" *(current.next)
    // Note the difference between reference and pointer.
    //
    // So the rule inferred from this code is that:
    //   When you want to follow objects in list where nodes are connected by pointer,
    //   use pointer not reference.
    Node* current = head; // This just copies the address of head.
    while(current->next != nullptr) {
        auto iter = if_appeared.find(current->next->value);
        if (iter != if_appeared.end()) {
            // Already exists other elements with the same value.
            Node* tmp = current->next;
            current->next = current->next->next;
            delete tmp;
        } else {
            if_appeared[current->next->value] = true;
        }
        if (current->next != nullptr) {
            current = current->next;
        }
    }
    return head;
}

Node* remove_dups_no_b(Node* head) {
    Node* current = head;
    while (current->next != nullptr) {
        Node* runner = current;
        while (runner->next != nullptr) {
            if (runner->next->value == current->value) {
                Node* tmp = runner->next;
                runner->next = runner->next->next;
                delete tmp;
            }
            if (runner->next != nullptr) {
                runner = runner->next;
            }
        }
        if (current->next != nullptr) {
            current = current->next;
        }
    }
    return head;
}

// Here also cannot use reference.
// Since you have to follow using pointers
// for next node.
// Pointer is better than just Node to avoid copies.
void show_all_elements(Node* head) {
    while (head->next != nullptr) {
        cout << head->value << endl;
        head = head->next;
    }
    // Since the last node is not revealed.}
    cout << head->value << endl;
}

void clean_up(Node* head){
    while (head != nullptr) {
        cout << "deleting this value: " << head->value << endl;
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}
int main(void) {
    vector<int> values{3, 4, 3, 2, 4};
    // Since nodes are new_ed here, all the elements have to be
    // delete_ed after operations.
    // Node ll1(6);
    // This above code raises error with clean_up function.
    // Because with this code memory is not allocated.
    Node* ll1 = new Node(6);
    for (auto e : values) {
        ll1->append_to_tail(e);
    }
    Node* ll2 = new Node(6);
    for (auto e : values) {
        ll2->append_to_tail(e);
    }
    cout << "original: " << endl;
    show_all_elements(ll1);

    Node* r1 = remove_dups(ll1);
    Node* r2 = remove_dups_no_b(ll2);

    cout << "remove dups" << endl;
    show_all_elements(r1);
    cout << "remove dups no buffer" << endl;
    show_all_elements(r2);

    // Clean up pointer.
    clean_up(r1);
    clean_up(r2);
}

