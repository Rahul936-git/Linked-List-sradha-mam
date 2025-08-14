#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class doublyLL{
    Node* head;
    Node* tail;

public:
    doublyLL(){
        head=NULL;
        tail=NULL;
    }

    void push_front(int val){

        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void printDLL(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    doublyLL dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    dll.printDLL();

    return 0;
}