/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool check(TreeNode* root){
        TreeNode* curr= root->right;  //smallest val of right subtree
        if(curr==nullptr) return true;
        while(curr->left!=nullptr){
            curr=curr->left;
        }
        if(curr->val <= root->val) return false;
        curr=root->left;
        while(curr->right!=nullptr){
            curr=curr->right;
        }
        if(curr->val >= root->val) return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        // if(root->left==nullptr && root->right==nullptr) return true;
        if(check(root)==false) return false;
        
        if((root->left)!=nullptr) if((root->left->val)>= (root->val)) return false;
        if((root->right)!=nullptr) if(root->right->val <= root->val) return false;
        if(isValidBST(root->left)==false) return false;
        if(isValidBST(root->right)==false) return false;
        return true;

    }
    
};