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

    void push_back(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
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

    void pop_front(){

        if(head==NULL){
           cout<<"DLL is empty"<<endl;  
           return;
        }
        Node* temp=head;
        head=head->next;

        if(head!=NULL){
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            cout<<"DLL is empty"<<endl;
            return;
        }

        Node* temp=tail;
        tail=tail->prev;

        if(tail!=NULL){
            temp->prev=NULL;        
            tail->next=NULL;
            delete temp;
        }
    }
};

int main(){
    doublyLL dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    dll.printDLL();  // 3<=>2<=>1<=>NULL
    
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);

    dll.printDLL();  // 3<=>2<=>1<=>1<=>2<=>3<=>NULL

    dll.pop_front();
    dll.pop_front();

    dll.printDLL();  //         1<=>1<=>2<=>3<=>NULL

    dll.pop_back();
    dll.pop_back();

    dll.printDLL(); //          1<=>1<=>NULL

    return 0;
}