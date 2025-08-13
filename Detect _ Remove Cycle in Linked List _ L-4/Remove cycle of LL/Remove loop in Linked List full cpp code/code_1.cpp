#include <iostream>
using namespace std;

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/

class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
  public:
    void removeLoop(Node* head) {
        if (!head || !head->next) return;

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // loop detected
                slow = head;
                Node* prev = NULL;

                while (slow != fast) {
                    prev = fast;
                    slow = slow->next;
                    fast = fast->next;
                }

                if (prev == NULL) { // loop starts at head
                    while (fast->next != slow) {
                        fast = fast->next;
                    }
                    fast->next = NULL; // break loop
                } else {
                    prev->next = NULL; // break loop
                }
                return;
            }
        }
    }
};

// Helper to print the list (stops if more than 20 nodes to avoid infinite loops)
void printList(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < 20) {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    if (temp != NULL) {
        cout << "...(loop detected if not removed)";
    } else {
        cout << "NULL";
    }
    cout << endl;
}

int main() {
    // Example 1: Loop starts in the middle
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    // Creating a loop: 5 -> 3
    head1->next->next->next->next->next = head1->next->next;

    Solution sol;
    sol.removeLoop(head1);
    cout << "List 1 after removing loop: ";
    printList(head1);

    // Example 2: Loop starts at head
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);
    head2->next->next->next = head2; // loop to head

    sol.removeLoop(head2);
    cout << "List 2 after removing loop: ";
    printList(head2);

    return 0;
}
