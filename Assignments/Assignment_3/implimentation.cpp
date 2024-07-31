#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define l(i,st,n) for(int i=st;i<n;i++)

// last two functionality remaining now


class Node{
    public:
        int data;
        Node* l;
        Node* r;
        Node* p;
        int bf;
        Node(int data,Node* l=nullptr,Node* r=nullptr,Node* p=nullptr,int bf=0){
            this->data=data;
            this->l=l;
            this->r=r;
            this->p=p;
            this->bf=bf;
        }
};

class AVL{
    public:
        Node* root=nullptr;

        Node* leftRotate(Node* A){
            if(A==nullptr) return A;
            Node* B=A->r;
            if(B==nullptr) throw "can't rotate";
            A->r=B->l;
            B->l=A;
            return B;
        }
        Node* rightRotate(Node* A){
            if(A==nullptr) return A;
            Node* B=A->l;
            if(B==nullptr) throw "can't rotate";
            A->l=B->r;
            B->r=A;
            return B;
        }
        int height(Node* A){
            if(A==nullptr) return -1;
            if(A->r==nullptr && A->l==nullptr) return 0;
            return 1+max(height(A->l),height(A->r));
        }

        Node* restore(Node* A){
            if(A->bf==2){
                if(A->r->bf>0) return leftRotate(A);
                else{
                    A->r=rightRotate(A->r);
                    return leftRotate(A);
                }  
            }else if(A->bf== -2){
                if(A->l->bf<0) return rightRotate(A);
                else{
                    A->l=leftRotate(A->l);
                    return rightRotate(A);
                }
            }else return A;
        }
        void my_update(Node* rt){
            rt->bf=(height(rt->r)-height(rt->l));
        }


        Node* insert(Node* rt,Node* A){
            // Node* temp=rt;
            if(rt==nullptr){
                return A;
            }
            else if(A->data==rt->data){
                cout<<"Already Exist\n";
                return A;
            }
            else if(A->data > rt->data){
                rt->r=insert(rt->r,A);
            } 
            else{
                rt->l=insert(rt->l,A);
            }
            my_update(rt);
           
            rt=restore(rt);
            return rt;
            
        }


        void insert(int a){
            Node* A=new Node(a);
            root =insert(root,A);
        }

        

        void inorder(Node* curr)
        {
            if(curr==nullptr) return;
            inorder(curr->l);
            cout<<curr->data<<"("<<curr->bf<<")  ";
            inorder(curr->r);
        }

        void preorder(Node* curr) {
            if (curr == nullptr) return;
            cout << curr->data << " "; 
            preorder(curr->l);
            preorder(curr->r);
        }

        void postorder(Node* curr) {
            if (curr == nullptr) return;
            postorder(curr->l);
            postorder(curr->r);
            cout << curr->data << " "; 
        }

        void show(){
            cout<<"Inorder: ";
            inorder(root);
            cout<<"  preorder: ";
            preorder(root);
            cout<<endl;
        }
        Node* getroot(){
            return root;
        }



        void order_of_key(){
            
        }

















};




int main(){
    
    AVL a;
    a.insert(10);
    a.show();
    a.insert(12);
    a.show();
    a.insert(15);
    a.show();
    a.insert(3);
    a.show();
    a.insert(4);
    a.show();
    a.insert(5);
    a.show();
    a.insert(6);
    a.show();
    a.insert(7);
    a.show();
}