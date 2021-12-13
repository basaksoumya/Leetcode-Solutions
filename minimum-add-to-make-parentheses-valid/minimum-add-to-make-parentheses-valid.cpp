class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        
        int open = 0, ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '(')
                open++;
            else {
                if(open <= 0)
                    ans++;
                else
                    open--;
            }
        }
        ans += open;
        open = 0;
        for(int i = n-1 ; i >= n ; i--) {
            if(s[i] == ')')
                open++;
            else {
                if(open <= 0)
                    ans++;
                else
                    open--;
            }
        }
        ans += open;
        return ans;
    }
};