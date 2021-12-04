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
    int kt;
    
    void inorder(TreeNode* root,int &ans) {
        if(root == NULL)
            return;
        
        inorder(root -> left,ans);
        if(kt == 1)
            ans = root -> val;
        kt--;
        inorder(root -> right,ans);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        kt = k;
        int ans;
        inorder(root,ans);
        return ans;
    }
};