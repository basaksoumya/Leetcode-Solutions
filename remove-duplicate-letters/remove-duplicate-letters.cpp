class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        if(n == 0 || n == 1)
            return s;
        
        unordered_map<char,int> mp;
        unordered_set<char> hash;
        stack<char> stk;
        
        for(int i = 0 ; i < n ; i++) {
            mp[s[i]]++;
        }
        
        for(int i = 0 ; i < n ; i++) {
            mp[s[i]]--;
            if(hash.find(s[i]) != hash.end()) {
                continue;
            }
            
            while(stk.size() > 0 && mp[stk.top()] > 0 && stk.top() > s[i])  {
                hash.erase(stk.top());
                stk.pop();
            }
            
            stk.push(s[i]);
            hash.insert(s[i]);
            
        }
        string ans = "";
        while(stk.size() > 0) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};