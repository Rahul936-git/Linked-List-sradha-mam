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

    Cll.printval();
    
    return 0;
}