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
    void preorder(TreeNode *root,string &pre)
    {
        if(root==NULL)
        {
            pre+='#';
            return;
        }
        pre+=','+to_string(root->val);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
	// Pre-processing the Longest Prefix Suffix array
    void preprecessLPS(string t1,int lps[])
    {
        
        lps[0]=0;
        int len=0;
        int i=1;
        while(i<t1.size())
        {
            if(t1[i]==t1[len])
            {
                
                lps[i++]=++len;
                
            }
            else{
                if(len!=0)
                {
                    len=lps[len-1];
                    
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
	
	   /* Converting S and T to its serialize form*/
        string s1;
        preorder(s,s1);
        string t1;
        preorder(t,t1);
       
        int lps[t1.size()];
        preprecessLPS(t1,lps);
        int i=0,j=0;
        
		// Pattern Matching
        while(i<s1.size())
        {
            if(s1[i]==t1[j])
            {
                i++;
                j++;
            }
            if(j==t1.size())
            {
                return true;
                
            }
            else if(i<s1.size()&&s1[i]!=t1[j])
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return false;
        
        
        
    }
};