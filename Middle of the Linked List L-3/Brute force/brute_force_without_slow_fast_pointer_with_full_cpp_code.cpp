#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Brute force approach: 2 passes
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        // First pass: count number of nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Second pass: move to middle
        int mid = count / 2; // floor division
        temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        return temp; // This is the middle node
    }
};

int main() {
    // Create example linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* middle = sol.middleNode(head);

    cout << "Middle node value: " << middle->val << endl;

    return 0;
}
