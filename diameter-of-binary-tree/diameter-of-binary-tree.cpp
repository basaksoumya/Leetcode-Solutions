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
    int diameterOfBinaryTreeUtill(TreeNode* root,int &ans) {
        if(root == NULL)
            return 0;
        
        if(!root->left && !root->right) {
            return 1;
        }
        
        int leftHeight = diameterOfBinaryTreeUtill(root->left,ans);
        int rightHeight = diameterOfBinaryTreeUtill(root->right,ans);
        
        ans = max(ans,leftHeight+rightHeight);
        
        
        int height = (leftHeight > rightHeight) ? leftHeight : rightHeight;
        
        return height + 1;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        if(!root->left && !root->right) {
            return 0;
        }
        
        int ans = INT_MIN;
        diameterOfBinaryTreeUtill(root,ans);
        return ans;
    }
};