class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = t.size();
        int ans = t[0] - 'a';
        for(int i = 1 ; i < n ; i++) {
            ans ^= (t[i] - 'a');
        }
        for(int i = 0 ; i < s.size() ; i++) {
            ans ^= (s[i] - 'a');
        }
        return ans + 'a';
    }
};