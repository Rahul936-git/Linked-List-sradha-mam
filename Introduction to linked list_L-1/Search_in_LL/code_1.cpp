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

    void printLL(){
        Node* temp= head;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    int search(int key){
        Node* temp = head;
        int idx=0;

        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }
};

int main(){
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.printLL();

    cout<<"idx: "<<ll.search(2)<<endl;
    cout<<"idx: "<<ll.search(1)<<endl;
    cout<<"idx: "<<ll.search(3)<<endl;
    cout<<"idx: "<<ll.search(9)<<endl;


    return 0;
}