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
    
    void hasPathSumUtill(TreeNode* root,int targetSum,bool &ans) {
        
        if(root == NULL)
            return;
        if(!root->left && !root->right) {
            if(root -> val == targetSum)
                ans = true;
            return;
        }
        
        hasPathSumUtill(root->left,targetSum-root->val,ans);
        hasPathSumUtill(root->right,targetSum-root->val,ans);
        
    }
    
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL && targetSum == 0)
            return false;
        if(root == NULL && targetSum != 0)
            return false;
        
        bool ans = false;
        hasPathSumUtill(root,targetSum,ans);
        return ans;
    }
};