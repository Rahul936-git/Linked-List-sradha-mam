#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> m; // old → new

        // Step 1: Copy nodes (next pointers)
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head] = newHead;

        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            newTemp->next = copyNode;
            m[oldTemp] = copyNode;
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        // Step 2: Copy random pointers
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL) {
            newTemp->random = (oldTemp->random != NULL) ? m[oldTemp->random] : NULL;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

// Helper function to print list with randoms
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Val: " << temp->val;
        if (temp->random) {
            cout << ", Random: " << temp->random->val;
        } else {
            cout << ", Random: NULL";
        }
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Creating a test list: 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2;
    n2->next = n3;

    // Setting random pointers
    n1->random = n3;
    n2->random = n1;
    n3->random = n2;

    cout << "Original List:\n";
    printList(n1);

    Solution sol;
    Node* copied = sol.copyRandomList(n1);

    cout << "\nCopied List:\n";
    printList(copied);

    return 0;
}
