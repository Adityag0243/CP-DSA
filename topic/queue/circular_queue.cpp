#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define val data


class Node{
    public:
    int data;
    Node* next;
    Node(int data,Node* next=nullptr){
     this->data=data;
     this->next=next;
    }
};
class Queue{
    int size=0;
    Node* head;
    Node* tail;
public:
    Queue(){
        head=tail=NULL;
        size=0;
    }
    void enqueue(int val){
        Node* newNode=new Node(val);
        newNode->next=head;
        if(size==0){
            head=newNode;
            tail=head;
            size+=1;
        }else{
            tail->next=newNode;
            tail=newNode;
            size+=1;
        }
    }

    void enqueueList(vector<int> v){
        l(i,0,v.size()){
            this->enqueue(v[i]);
        }
    }

    void display(){
        Node* itr=head;
        cout<<itr->val<<" ->";
        itr=head->next;
        while(itr!=head){
            cout<<itr->val<<" ->";
            itr=itr->next;
        }
        cout<<endl;
    }
    bool isempty(){
        return size==0;
    }
    void dequeue(){
        if(isempty()) throw out_of_range("No element present in Queue");
        else if(size==1){
            head=NULL;
            tail=head;
        }else{
            Node* temp=head;
            head=head->next;
            temp=NULL;
            tail->next=head;
            size-=1;
        }
    }

    int front(){
        return head->val;
    }
    int back(){
        return tail->val;
    }
    int len(){
        return size;
    }
    bool contains(int value){
        Node* itr=head;
        if(itr->val==value) return true;
        itr=itr->next;
        while(itr!=head){
            if(itr->val==value) return true;
            itr=itr->next;
        }
        return false;
    }






};

int main(){
    Queue A;
    cout<<A.isempty()<<endl;
    A.enqueue(5);
    A.enqueue(7);
    A.display();
    cout<<A.contains(7)<<endl;
    cout<<A.contains(8)<<endl;

    A.dequeue();
    A.display();

    A.dequeue();
    A.display();
    Queue B;
    B.enqueueList({1,2,3});
    B.display();
    cout<<B.isempty()<<endl;
    B.dequeue();
    B.dequeue();
    B.display();
    B.dequeue();
    // A.dequeue();
    B.enqueueList({1,2,3});
    B.display();
    cout<<B.contains(3)<<endl;   
    
}