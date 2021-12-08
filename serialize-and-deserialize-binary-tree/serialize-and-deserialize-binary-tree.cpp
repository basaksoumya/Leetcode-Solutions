/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL)
            return "";
        queue<TreeNode*> q;
        string ans = "";
        q.push(root);
        
        while(!q.empty()) {
            TreeNode *temp = q.front();
            if(temp == NULL)
                ans += '#';
            else
                ans += to_string(temp -> val);
            ans += ',';
            q.pop();
            if(temp != NULL) {
                q.push(temp -> left);
                q.push(temp -> right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        
        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            getline(s,str,',');
            if(str != "#") {
                curr -> left = new TreeNode(stoi(str));
                q.push(curr->left);
            }else{
                curr -> left = NULL;
            }
            getline(s,str,',');
            if(str != "#") {
                curr -> right = new TreeNode(stoi(str));
                q.push(curr->right);
            }else {
                curr -> right = NULL;
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));