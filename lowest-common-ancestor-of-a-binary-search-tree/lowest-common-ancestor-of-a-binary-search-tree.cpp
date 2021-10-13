/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root == p || root == q)
            return root;
        
        TreeNode *temp1 = lowestCommonAncestor(root->left,p,q);
        TreeNode *temp2 = lowestCommonAncestor(root->right,p,q);
        
        if(temp1 && temp2)
            return root;
        if(temp1)
            return temp1;
        return temp2;
    }
};