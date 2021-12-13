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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> nodes;
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()) {
            pair<TreeNode*,pair<int,int>> temp = q.front();
            TreeNode *Node = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            q.pop();
            nodes[x][y].insert(Node -> val);
            if(Node->left) {
                q.push({Node->left,{x-1,y+1}});
            }
            if(Node -> right) {
                q.push({Node->right,{x+1,y+1}});
            }
            
        }
        
        for(auto p : nodes) {
            vector<int> arr;
            for(auto q : p.second) {
                arr.insert(arr.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(arr);
        }
        
        return ans;
    }
};