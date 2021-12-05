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
    
    vector<int> houseRobber(TreeNode* root) {
        if(root == NULL) {
            vector<int> ans(2,0);
            return ans;
        }
        
        vector<int> left = houseRobber(root->left);
        vector<int> right = houseRobber(root -> right);
        
        vector<int> ans(2,0);
        
        ans[0] = max(left[0],left[1]) + max(right[0],right[1]);
        
        ans[1] = root -> val + left[0] + right[0];
        
        return ans;
    }
    
    
    int rob(TreeNode* root) {
        vector<int> ans(2,0);
        ans = houseRobber(root);
        return max(ans[0],ans[1]);
    }
};