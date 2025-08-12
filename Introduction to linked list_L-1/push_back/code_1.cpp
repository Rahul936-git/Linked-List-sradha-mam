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

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head=tail=NULL;
    }

    void push_front(int val){
        // Node newNode(val); // static 
        Node* newNode = new Node(val); // Dynamic  

        if(head==NULL){
            head=tail=newNode;
            return;
        }
        else{
            // (*newNode).next = head;
            newNode->next= head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode= new Node(val);

        if(head==NULL)  // Linked List is empty 
        head= tail= newNode;

        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void printLL(){
        Node* temp= head;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);

    ll.printLL();

    return 0;
}