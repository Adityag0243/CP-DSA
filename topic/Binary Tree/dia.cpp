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
    int Depth(TreeNode* root) {
        int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        
        if(root->left==nullptr && root->right==nullptr) return 1;
        int l=0,r=0;
        if(root->left!=nullptr) l=maxDepth(root->left);
    
        if(root->right!=nullptr) r=maxDepth(root->right);

        return 1+max(l,r);
    }
    }
    

    int sumDepth(TreeNode* root) {
        int l=0,r=0;
        if(root->left!=nullptr) l=maxDepth(root->left);
        if(root->right!=nullptr) r=maxDepth(root->right);
        return l+r;

    }




    int dia=0;
    int diameterOfBinaryTree(TreeNode* root) {
        
    }
    
};
