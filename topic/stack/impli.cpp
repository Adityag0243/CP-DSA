#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node *next;
    Node(int data,Node *next=NULL){
        this->data=data;
        this->next=next;
    }

};


class Stack{

    public:
    int size=0;
    Node* head;
    Stack(){
        size=0;
        head=NULL;
    }

    void push(int num){
        Node *a = new Node(num);
        if(size==0){
            head=a;
            this->size++;
        }else{
            size++;
            a->next=head;
            this->head=a;
        }
    }


    int top(){
        return head->data;
    }


    bool isempty(){
        if(size==0) return true;
        else return false;
    }

    int pop(){
        if(size==0) return -1;
        else{
            int value=head->data;
            head = head->next;
            size--;
            return value;
        }
    }
};

int main(){

    Stack s;
    cout<<s.isempty()<<endl;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(7);
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.isempty();

}