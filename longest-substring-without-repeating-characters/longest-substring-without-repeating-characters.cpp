class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 || n == 1) 
            return n;
        
        vector<int> map(256,-1);
        int left = 0 , right = 0, ans = 0;
        
        while(right < n) {
            
            if(map[s[right]] != -1)
                left = max(left,map[s[right]]+1);
                
                map[s[right]] = right;
                ans = max(ans,right - left + 1);
                right++;
        }
        return ans;
    }
};