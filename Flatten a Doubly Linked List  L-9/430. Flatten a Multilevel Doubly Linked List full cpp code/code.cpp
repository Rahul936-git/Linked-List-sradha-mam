#include <iostream>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {
                // Save next pointer
                Node* next = curr->next;

                // Recursively flatten the child
                Node* child = flatten(curr->child);
                curr->next = child;
                child->prev = curr;
                curr->child = NULL;

                // Move curr to the tail of the flattened child
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // Reconnect with saved next
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};

// Utility function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    // Example construction:
    // 1 - 2 - 3 - 4 - 5 - 6
    //         |
    //         7 - 8 - 9 - 10
    //             |
    //             11 - 12

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    // Main list
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;

    // Child lists
    n3->child = n7;
    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;
    n9->next = n10; n10->prev = n9;

    n8->child = n11;
    n11->next = n12; n12->prev = n11;

    Solution sol;
    Node* flatHead = sol.flatten(n1);

    cout << "Flattened List: ";
    printList(flatHead);

    return 0;
}
