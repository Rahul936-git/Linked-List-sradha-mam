#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // check if k nodes exist
        while (cnt < k) {
            if (temp == NULL) {
                return head;
            }
            temp = temp->next;
            cnt++;   // ✅ fix
        }

        // recursively call for rest of LL
        ListNode* prevNode = reverseKGroup(temp, k);   // ✅ fix

        // reverse current group
        temp = head;
        cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;

            cnt++;
        }
        return prevNode;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to insert at end
void insertAtEnd(ListNode*& head, int val) {
    if (head == NULL) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

int main() {
    ListNode* head = NULL;

    // create linked list: 1->2->3->4->5
    for (int i = 1; i <= 5; i++) {
        insertAtEnd(head, i);
    }

    cout << "Original list: ";
    printList(head);

    Solution sol;
    int k = 2;
    head = sol.reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
