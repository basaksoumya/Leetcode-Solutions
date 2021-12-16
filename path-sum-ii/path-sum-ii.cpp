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
    
    void pathSumRecursive(TreeNode* root,int target,vector<int> &temp, vector<vector<int>> &ans) {
        if(root == NULL)
            return;
        
        if(root -> left == 0 && root -> right == 0 && target == root -> val) {
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        target -= root -> val;
        pathSumRecursive(root->left,target,temp,ans);
        pathSumRecursive(root->right,target,temp,ans);
        temp.pop_back();
    }
    
    
    
    
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        pathSumRecursive(root,targetSum,temp,ans);
        return ans;
    }
};