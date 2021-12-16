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
    void pathSumRecursive(TreeNode* root,int sum,int &ans) {
        if(root == NULL)
            return;
        
        if(root -> left == NULL && root -> right == NULL) {
            sum *= 10;
            sum += root -> val;
            ans += sum;
            return;
        }
        else{
            
            sum *= 10;
            sum += root -> val;
            pathSumRecursive(root->left,sum,ans);
            pathSumRecursive(root->right,sum,ans);         
        }

    }    
    
    
    int sumNumbers(TreeNode* root) {
        int ans = 0,sum = 0;
        pathSumRecursive(root,sum,ans);
        return ans;        
    }
};