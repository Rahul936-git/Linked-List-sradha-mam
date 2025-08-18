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
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while(first != NULL && sec != NULL){
            ListNode* third = sec->next;

            // swap first and sec
            sec->next = first;
            first->next = third;

            if(prev != NULL){
                prev->next = sec;
            } else {
                head = sec;   // update head on first swap
            }

            prev = first;
            first = third;

            if(third != NULL){
                sec = third->next;
            } else {
                sec = NULL;
            }
        }
        return head;
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

    cout << "After swapping in pairs: ";
    printList(head);

    return 0;
}
