#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        Node* l;
        Node* r;
        Node* p;
        Node(char data,Node* l=nullptr,Node* r=nullptr,Node* p=nullptr){
            this->data=data;
            this->l=l;
            this->r=r;
            this->p=p;
        }
};


void inorder(Node* curr)
{
    if(curr==nullptr) return;
    if(curr->l!=nullptr){
        inorder(curr->l);
    }
    cout<<curr->data<<" ";
    
    if(curr->r!=nullptr){
        inorder(curr->r);

    }
}

void preorder(Node* curr){      //wrong
    if(curr==nullptr) return;
    
    cout<<curr->data<<" ";
    if(curr->l!=nullptr){
        inorder(curr->l);
    }
    if(curr->r!=nullptr){
        inorder(curr->r);

    }
}


bool search(char a,Node* curr){
    if(curr==nullptr) return false;
    if(curr->data==a) return true;
    else if(curr->l!=nullptr){
        if(search(a,curr->l)==true){
            return true;
        }
    }
    else if(curr->r!=nullptr){
        if(search(a,curr->r)==true){
            return true;
        }
    }
    return false;
}



int main(){
    Node* root=new Node('A');
    Node* node1a=new Node('B');
    root->l=node1a;
    Node* node1b=new Node('C');
    root->r=node1b;
    Node* node2aa=new Node('D');
    Node* node2ab=new Node('E');
    node1a->l=node2aa;
    node1a->r=node2ab;
    Node* node2ba=new Node('F');
    Node* node2bb=new Node('G');
    node1b->l=node2ba;
    node1b->r=node2bb;

    // inorder(root);
    // cout<<endl;
    // preorder(root);
    cout<<search('F',root);
}