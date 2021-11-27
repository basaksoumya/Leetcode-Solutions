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
    
    bool isValidRecursive(TreeNode *currentNode,TreeNode* min,TreeNode *max) {
        if (currentNode==NULL) return true;               
        if (min && currentNode->val <= min->val) return false;
        if (max && currentNode->val >= max->val) return false;

        return isValidRecursive (currentNode->left, min, currentNode) && isValidRecursive (currentNode->right, currentNode, max);
    }
    
    
    
    
    
    bool isValidBST(TreeNode* root) {
        bool ans = isValidRecursive(root,NULL,NULL);
        return ans;
    }
};