// first two part was in leet code submitted already on leet code
// 3rd and 5th remaining 
// 4th trying to do it but got stuck somewhere


#include<bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* insert(TreeNode* rt,int val){
        if(rt==nullptr){
            TreeNode* n1=new TreeNode(val);
            if(rt==nullptr){
                rt=n1;
                return rt;
            }
            return n1;
        }
        
        if(rt==nullptr){
            TreeNode* n1=new TreeNode(val);
            rt=n1;
            rt=rt;
            return rt;
        }else{
            if(val == rt->val) return rt;
            else if(val < rt->val){
                rt->left= insert(rt->left,val);
            }else{
                rt->right= insert(rt->right,val);
            }
        }
        return rt;
    }

    void call(TreeNode* rt,vector<int> &v,int st, int high){
        int mid=(st+high)>>1;
        if(mid<0 || mid>=v.size() || v[mid]<0) return;
        insert(rt,v[mid]);
        v[mid]*=(-1);
        call(rt,v,st,mid);
        call(rt,v,mid,high);
    }

    void inorder(vector<int> &v,TreeNode* root){
        if(root==nullptr) return;
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(v,root);
        TreeNode* rt=new TreeNode(v[v.size()/2]);
        call(rt,v,0,v.size());
        return rt;
    }




    //(firstly I have implimentated all these in term my variable later realize i need to merge it with leetcode)
    #define r right
    #define l left
    #define data val

    void count_inorder(int& count,TreeNode* curr){
        if(curr==nullptr) return;
        count_inorder(count,curr->left);
        count++;
        count_inorder(count,curr->right);
    }

    TreeNode* node_by_key(TreeNode* temp,int key){
            if(!temp) return NULL;
            if( temp->data == key) return temp;
            if( temp->data > key ) return node_by_key(temp->l,key);
            else return node_by_key(temp->r,key);
    }
    TreeNode* node_by_key(int key){
        return node_by_key(root,key);  // showing error for this root not able find why
    }



    int order_of_key(int key){
        TreeNode* temp=node_by_key(key);   // as i need to make a bst class object then call it
        if(!temp) return -1;
        // then calculate all element of left subtree by (here doing count++ in inorder traversal
        int count=0;
        count_inorder(count,temp);  
        return count;
    }
};