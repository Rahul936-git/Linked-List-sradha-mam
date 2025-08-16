#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class CircularList{
    Node* head;
    Node* tail;
public:
    CircularList(){
        head=tail=NULL;
    }

    void inserAtHead(int val){
        Node* newNode = new Node(val);

        if(tail==NULL){    // Empty
            head=tail=newNode;
            tail->next=head;
        }
        else{
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }

    void deleteAtTail(){
        if(head==NULL){ // Empty
            return;
        }

        if(head==tail){
            delete head;
            head=tail=NULL;
        }

        Node* temp=tail;
        Node* prev=head;

        while(prev->next!=tail){
            prev=prev->next;
        }
            tail=prev;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }

    void printval(){
        if(head==NULL){
            return;
        }
        cout<<head->data<<"->";
        Node*temp=head->next;

        while(temp!=head){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
};

int main(){
    CircularList Cll;

    Cll.inserAtHead(1);
    Cll.inserAtHead(2);
    Cll.inserAtHead(3);
    Cll.inserAtHead(4);
    Cll.inserAtHead(5);
    Cll.inserAtHead(6);

    Cll.printval();        // 6->5->4->3->2->1->6

    Cll.deleteAtTail();
    Cll.deleteAtTail();

    Cll.printval();        // 6->5->4->3->6

    return 0;
}