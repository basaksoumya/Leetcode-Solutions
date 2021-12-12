class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        
        vector<vector<bool>> dp(m+1,vector<bool>(m+1,false));
        
        for(int i = 0 ; i <= m ; i++) {
            for(int j = 0 ; j <= n ; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                else if(i == 0) {
                    dp[i][j] = false;
                }
                else if(j == 0) {
                    if(p[i-1] == '*') {
                        dp[i][j] = dp[i-2][j];
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
                else {
                    
                    if(p[i-1] == '*') {
                        dp[i][j] = dp[i-2][j];
                        if(p[i-2] == s[j-1] || p[i-2] == '.') {
                            dp[i][j] = dp[i][j-1] || dp[i][j];
                        }
                    }
                    else if(p[i-1] == '.') {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(p[i-1] == s[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};