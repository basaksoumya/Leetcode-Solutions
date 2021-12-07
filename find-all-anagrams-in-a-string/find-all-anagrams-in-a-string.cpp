class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(),window = p.size();
        vector<int> ans;
        
        if(window > n)
            return ans;
        
        vector<int> hash(26,0),phash(26,0);
        
        for(int i = 0 ; i < window ; i++) {
            phash[p[i]-'a']++;
        }
        
        int ptr = 0;
        
        while(ptr < window) {
            hash[s[ptr++]-'a']++;
        }
        int start = 0;
        while(ptr < n) {
            if(phash == hash)
                ans.push_back(start);
            hash[s[start++]-'a']--;
            hash[s[ptr++]-'a']++;
        }
        if(hash == phash)
            ans.push_back(start);
        
        return ans;
    }
};