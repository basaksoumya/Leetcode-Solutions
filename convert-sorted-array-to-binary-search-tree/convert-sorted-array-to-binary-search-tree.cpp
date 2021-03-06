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
    
    TreeNode* buildBST(vector<int> &nums,int left,int right) {
        
        if(left > right) 
            return NULL;
        
        int mid = (left + right) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root -> left = buildBST(nums,left,mid-1);
        root -> right = buildBST(nums,mid+1,right);
        
        return root;
    }
    
    
    
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) 
            return NULL;
        int left = 0,right = nums.size()-1;
        TreeNode* root = buildBST(nums,left,right);
        return root;
    }
};