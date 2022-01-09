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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 1;
        if(root == NULL)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()) {
            int size = q.size();
            int first,last,minn = q.front().second;
            for(int i = 0 ; i < size ; i++) {
                pair<TreeNode*,int> node = q.front();
                int curr_idx = node.second - minn;
                if(i == 0)
                    first = node.second-minn;
                if(i == size - 1)
                    last = node.second-minn;
                q.pop();
                if(node.first -> left)
                    q.push({node.first ->left,(curr_idx)*2+1});
                if(node.first -> right)
                    q.push({node.first ->right,(curr_idx)*2+2});
            }
            ans = max(ans,last-first+1);
        }
        
        return ans;
    }
};