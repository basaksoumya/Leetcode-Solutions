class Solution {
public:
    //Brute Force Method
//     int solve(vector<int> &coins,int i,int amount,int count,vector<vector<int>> &dp) {
//         if(amount == 0) {
//             return count;
//         }
        
//         if(i >= coins.size())
//             return INT_MAX;
        
//         if(amount < 0)
//             return INT_MAX;
        
//         int a = solve(coins,i,amount-coins[i],count+1,dp);
//         int b = solve(coins,i+1,amount,count,dp);
        
//         return min(a,b);
//     }
    
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0 && coins.size() > 0)
            return 0;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        
//         for(int i = 0 ; i < n+1 ; i++) {
//             for(int j = 0 ; j < amount+1 ; j++) {
//                 if(j == 0)
//                     dp[i][j] = 0;
//                 else if(i == 0) 
//                     dp[i][j] = INT_MAX;
//                 else if(coins[i-1] > j)
//                     dp[i][j] = dp[i-1][j];
//                 else
//                     dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
//             }
//         }
        
        
        
//         return (dp[n][amount] == INT_MAX) ? -1 : dp[n][amount];
        
        for(int i=0;i<n+1;++i)
        {
            for(int j=0;j<amount+1;++j)
            {
                if(j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = 1e5;
                else if(coins[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            }
        }
        return dp[n][amount]==1e5 ? -1:dp[n][amount];
    }
};