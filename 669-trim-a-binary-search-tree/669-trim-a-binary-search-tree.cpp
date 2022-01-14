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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL)
            return root;
        
        if(root -> val < low || root -> val > high) {
            TreeNode* temp = root;
            root -> left = trimBST(root->left,low,high);
            root -> right = trimBST(root->right,low,high);
            if(root->left)
                root = root -> left;
            else 
                root = root -> right;
            return root;
        }
        
        root -> left = trimBST(root->left,low,high);
        root -> right = trimBST(root->right,low,high);
        return root;
    }
};