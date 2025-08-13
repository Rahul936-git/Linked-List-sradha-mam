/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                slow=head;
                Node* prev=NULL;
                
                while(slow!=fast){
                    prev=fast;
                    slow=slow->next;
                    fast=fast->next;
                }
                
                if(prev==NULL){  // when loop starts at head
                   while(fast->next!=slow){
                       fast=fast->next;
                   }
                    fast->next=NULL;
                }
                else{
                    prev->next=NULL;
                }
            }
        }
    }
};