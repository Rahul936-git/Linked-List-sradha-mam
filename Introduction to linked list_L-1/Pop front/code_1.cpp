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

    void pop_front(){
        if(head == NULL){
            cout<<"LL is empty"<<endl;
        }

        Node* temp= head;
        head=head->next;
        temp->next=NULL; 

        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            cout<<"LL is empty"<<endl;
        }

        Node* temp =head;
        while(temp->next != tail){ // temp->next->next == NULL
            temp=temp->next;
        }

        temp->next=NULL;
        delete tail;
        tail=temp;
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
    ll.printLL();

    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);
    ll.printLL();

    ll.pop_front();
    ll.printLL();

    ll.pop_back();
    ll.printLL();

    return 0;
}