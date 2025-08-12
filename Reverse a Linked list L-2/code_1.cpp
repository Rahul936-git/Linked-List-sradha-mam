// 206. Reverse Linked List

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;

        while(curr != NULL){
            next=curr->next;
            curr->next = prev;

            prev=curr;
            curr=next;
        }
        return prev;
    }
};


// tc: 0(n)
// sc: 0(1)