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
    
    void AllPaths(TreeNode* root,string curr, vector<string> &ans) {
        if(root == NULL)
            return;
        if(!root -> left && !root->right) {
            curr += to_string(root->val);
            ans.push_back(curr);
            return;
        }
        
        curr += to_string(root->val) + "->";
        AllPaths(root->left,curr,ans);
        AllPaths(root->right,curr,ans);
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curr = "";
        AllPaths(root,curr,ans);
        return ans;
    }
};