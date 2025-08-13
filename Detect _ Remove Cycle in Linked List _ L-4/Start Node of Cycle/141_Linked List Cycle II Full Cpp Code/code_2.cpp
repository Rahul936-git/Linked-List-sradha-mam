#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Cycle detected
                // Step 2: Find start of cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Start node of the cycle
            }
        }
        return NULL; // No cycle
    }
};

int main() {
    // Create nodes
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Link nodes to form a cycle: 3 -> 2 -> 0 -> -4 -> back to 2
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates cycle

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);

    if (cycleStart != NULL) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
