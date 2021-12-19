class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        
        vector<string> stk;
        int n = path.size();
        
        for(int i = 0 ; i < n ; i++) {
            string curr = "";
            while(i < n && path[i] != '/') {
                curr += path[i++];
            }
            if(curr == "" or curr == ".") {
                continue;
            }
            else if(curr == "..") {
                if(stk.size())
                    stk.pop_back();    
            }
            else{
                stk.push_back(curr);
            }
        }
        
        for(int i = 0 ; i < stk.size() ; i ++) {
            ans  += "/" + stk[i];
        }
        if(ans == "")
            return "/";
        return ans;
    }
};