class Solution {
    bool isPalindrome(string &s,int start,int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    
    void DFS(string &s,int index,vector<string> &path,vector<vector<string>> &ans) {
        if(index == s.size()) {
            ans.push_back(path);
            return;
        }
        
        for(int i = index ; i < s.size() ; i++) {
            if(isPalindrome(s,index,i)) {
                path.push_back(s.substr(index,i-index+1));
                DFS(s,i+1,path,ans);
                path.pop_back();
            }
        }
    }
    
    
public:
    
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        DFS(s,0,path,ans);
        return ans;
    }
};