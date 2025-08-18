#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // base case: 0 or 1 node, nothing to swap
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;

        // Recursively swap remaining list
        first->next = swapPairs(second->next);

        // Swap first and second
        second->next = first;

        // second becomes new head
        return second;
    }
};

// Utility function to print linked list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Utility function to insert node at end
void insertEnd(ListNode*& head, int val) {
    if(head == NULL) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

int main() {
    ListNode* head = NULL;

    // create linked list: 1 -> 2 -> 3 -> 4 -> 5
    for(int i=1; i<=5; i++) {
        insertEnd(head, i);
    }

    cout << "Original list: ";
    printList(head);

    Solution s;
    head = s.swapPairs(head);

    cout << "After swapping in pairs (recursive): ";
    printList(head);

    return 0;
}
