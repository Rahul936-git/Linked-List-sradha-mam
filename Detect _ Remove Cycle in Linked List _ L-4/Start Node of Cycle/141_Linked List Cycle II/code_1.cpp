// 142. Linked List Cycle II

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                slow=head;
            
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
                return slow;
            }
        }
        return NULL;
    }
};

// tc: 0(n)
// sc: 0(1)