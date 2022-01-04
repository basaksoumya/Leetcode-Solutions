class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i = 0 ; i < n ;i++) 
            dp[i][i] = 1;
        int k = 1;
        
        while(k < n) {
            int i = 0;
            int j = k;
            while(i < n && j < n) {
                if(s[i] == s[j]) {
                    dp[i][j] = 1;
                    if(i+1 <= j-1) {
                        if(dp[i+1][j-1] && dp[i][j])
                         dp[i][j] = 1;
                        else
                         dp[i][j] = 0;
                        
                    }
                } 
                else{
                    dp[i][j] = 0;
                }
                i++,j++;
            }
            k++;
        }
        
        k = 0;
        int maxi = INT_MIN;
        pair<int,int> substr;
        while(k < n) {
            int i = 0;
            int j = k;
            while(i < n && j < n) {
                if(dp[i][j] == 1) {
                    if(maxi < j-i+1) {
                    	maxi = j-i+1;
                    	substr.first = i;
                    	substr.second = j;
					}
                }
                i++,j++;
            }
            k++;
        }
        string ans ="";
        for(int i = substr.first; i <= substr.second ; i++) {
            ans += s[i];
        }
        
        return ans;
    }
};