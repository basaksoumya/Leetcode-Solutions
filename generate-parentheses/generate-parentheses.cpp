class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0)
            return ans;
        backtrack(ans,"",0,0,n);
        return ans;
    }
    
    void backtrack(vector<string> &ans,string curr,int open,int close,int max) {
        if(curr.size() == 2*max) {
            ans.push_back(curr);
            return;
        }
        
        if(open < max)
            backtrack(ans,curr+"(",open+1,close,max);
        if(close < open) 
            backtrack(ans,curr + ")",open,close+1,max);
    }
};