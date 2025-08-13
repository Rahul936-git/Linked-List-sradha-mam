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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;         // move slow by 1
            fast = fast->next->next;   // move fast by 2

            if (slow == fast) {        // cycle detected
                return true;
            }
        }
        return false;  // no cycle found
    }
};

// Example usage
int main() {
    // Creating a list: 1 -> 2 -> 3 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution sol;
    cout << (sol.hasCycle(head) ? "Cycle detected" : "No cycle") << endl;

    // Creating a cycle for testing: 3 -> 2
    head->next->next->next = head->next;
    cout << (sol.hasCycle(head) ? "Cycle detected" : "No cycle") << endl;

    return 0;
}
