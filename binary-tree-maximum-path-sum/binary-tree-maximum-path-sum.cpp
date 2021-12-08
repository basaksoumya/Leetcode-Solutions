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
    int maxPathSumRecursive(TreeNode* root,int &ans) {
        
        if(root == NULL)
            return -100000;
        
        if(root->left == NULL && root->right == NULL) {
            ans = max(ans,root->val);
            return root -> val;
        }
        
         

        
        int leftMaxPathSum = maxPathSumRecursive(root->left,ans);
        int rightMaxPathSum = maxPathSumRecursive(root->right,ans);
        
        int bothSum = leftMaxPathSum + rightMaxPathSum + root->val;
        
        ans = max(ans,bothSum);
        ans = max(ans,max(leftMaxPathSum,rightMaxPathSum));
        int leftSum = leftMaxPathSum + root -> val;
        int rightSum = rightMaxPathSum + root -> val;
        
        int temp = max(root->val,max(leftSum,rightSum));
        
        ans = max(ans,temp);
        
        return temp;
    }
    
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return -100000;
        int ans = INT_MIN;
        maxPathSumRecursive(root,ans);
        return ans;
    }
};