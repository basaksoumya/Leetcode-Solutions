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
    
    void minDepthUtill(TreeNode* root,int level, int &ans) {
        
        if(!root)
            return;
        
        if(!root->left && !root->right) {
            ans = min(ans,level);
            return;
        }
        
        minDepthUtill(root->left,level+1,ans);
        minDepthUtill(root->right,level+1,ans);
    }
    
    
    
    int minDepth(TreeNode* root) {
        int level = 1,ans = INT_MAX;
        if(root == NULL)
            return 0;
        minDepthUtill(root,level,ans);
        return ans;
    }
};