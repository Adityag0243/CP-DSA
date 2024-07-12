#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++)
#define rl(i,st,n) for(int i=n-1;i>=st;i--)
#define srt(v) sort(v.begin(),v.end())
class node{
    public:
        int val;
        node* l;
        node* r;
        node(int val, node* l=nullptr,node* r=nullptr){
            this->val=val;
            this->l=l;
            this->r=r;
        }
};

class BST{
    
    node* root;
    public:
        BST(){
            root=nullptr;
        }

        void inorder(node* rt){
            if(rt==nullptr) return;
            inorder(rt->l);
            cout<<(rt->val)<<" ";
            inorder(rt->r);
        }

        void preorder(node *rt){
            if(rt==nullptr) return;
            cout<<(rt->val)<<" ";
            preorder(rt->l);
            preorder(rt->r);
        }







        node* insert(node* rt,int val){
            if(rt==nullptr){
                node* n1=new node(val);
                if(root==nullptr){
                    root=n1;
                    return root;
                }
                return n1;
            }
            
            if(root==nullptr){
                node* n1=new node(val);
                rt=n1;
                root=rt;
                cout<<"here "<<root->val<<"  "<<rt->val<<"  ";
                return rt;
            }else{
                if(val == rt->val) return rt;
                else if(val < rt->val){
                    rt->l= insert(rt->l,val);
                }else{
                    rt->r= insert(rt->r,val);
                }
            }
            
            return rt;
        }
        void insert(int val) {
            root = insert(root, val);
        }
        void inorder(){
            inorder(root);
        }
        void preorder(){
            preorder(root);
        }

        node* remove(node* rt,int data){
            if(rt==NULL) return rt;        //will handle if unknown data came
            if(rt->val==data){
                if(rt->l == nullptr && rt->r == nullptr){
                    rt=nullptr;
                    return rt;
                }else if(rt->r == nullptr){
                    node* temp=rt->l;
                    rt=nullptr;
                    rt=temp;
                    return rt;
                }else if(rt->l == nullptr){
                    node* temp=rt->r;
                    rt=nullptr;
                    rt=temp;
                    return rt;
                }else{
                    int leftlarge;
                    node* temp=rt->l;
                    while(temp->r!=nullptr){
                        temp=temp->r;
                    }
                    leftlarge=temp->val;
                    rt=remove(rt,leftlarge);
                    rt->val=leftlarge;
                    return rt;
                }
            }
            if(rt->val < data){
                rt->r = remove(rt->r,data);
                return rt;
            }else if(rt->val > data){
                rt->l = remove(rt->l,data);
                return rt;
            }
        }

        node* remove(int data){
            root=remove(root,data);
            return root;
        }
        void insert(vector<int>v){
            l(i,0,v.size()) this->insert(v[i]);
        }

        bool find(node* rt,int data){
            if(rt==nullptr) return false;
            if(rt->val == data) return true;
            if(data > rt->val ){
                return find(rt->r,data);
            }else{
                return find(rt->l,data);
            }
        }

        bool find(int data){
            return find(root,data);
        }
        // int max(node* rt){
        //     if(rt==nullptr) return INT_MIN;
        // }


        // int max(){
        //     return max(root);
        // }
        

        
    
};




int main(){
    BST a;
    // a.insert(5);
    // a.insert(4);
    // a.insert(7);
    // a.insert(6);
    // a.insert(10);
    // a.insert(11);
    // a.insert(2);
    // a.insert(8);
    // a.insert(3);
    a.insert({20,10,25,23,30,28,35,22,24,21});
    a.inorder();
    cout<<endl;
    a.remove(25);
    a.inorder();
    cout<<endl;
    a.preorder();
    cout<<endl;
    cout<<a.find(25);





}