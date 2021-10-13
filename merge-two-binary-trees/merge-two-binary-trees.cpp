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
    
    TreeNode* buildTree(TreeNode* root,TreeNode* root1) {
        if(root1 == NULL) {
            return root;
        }
        
        if(root == NULL) {
            root = new TreeNode;
            root -> val = root1 -> val;
        }
        else{
            root -> val += root1 -> val;
        }
        
        root -> left = buildTree(root->left,root1->left);
        root -> right = buildTree(root->right,root1->right);
        return root;
    }
    
    
    
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *root = NULL;
        
        root = buildTree(root,root1);
        root = buildTree(root,root2);
        
        return root;
    }
};