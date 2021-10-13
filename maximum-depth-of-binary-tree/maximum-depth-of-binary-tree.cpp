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
    
    void maxDepthUtill(TreeNode* root,int depth,int &ans) {
        if(root==NULL) {
            return;
        }
        if(!root->left && !root->right) {
            ans = max(ans,depth);
            return;
        }
        maxDepthUtill(root->left,depth+1,ans);
        maxDepthUtill(root->right,depth+1,ans);
    }
    
    
    
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = INT_MIN, depth = 1;
        maxDepthUtill(root,depth,ans);
        return ans;
    }
};