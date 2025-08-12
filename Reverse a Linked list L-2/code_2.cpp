#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    // Create linked list: 1 -> 2 -> 3 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // Reverse list
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next; // save next node
        curr->next = prev; // reverse link
        prev = curr;       // move prev forward
        curr = next;       // move curr forward
    }

    head = prev; // new head after reversal

    // Print reversed list
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
