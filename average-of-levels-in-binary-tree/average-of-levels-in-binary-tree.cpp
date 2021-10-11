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
    
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty() && q.size() != 1) {
            double avg = 0.0;
            long long int sum = 0, levelSize = 0;
            while(q.front() != NULL) {
                TreeNode *curr = q.front();
                q.pop();
                sum += curr -> val;
                levelSize++;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            q.pop();
            if(levelSize != 0)
               avg = (double)sum / (double)levelSize;
            ans.push_back(avg);
            q.push(NULL);
        }
        return ans;
    }
};