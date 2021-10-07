class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 , n = prices.size();
        if(n == 0 || n == 1) 
            return 0;
        
       int minimumValue = prices[0];
        
        for(int i = 0 ; i < n ; i++) {
            minimumValue = min(minimumValue,prices[i]);
            profit = max(prices[i] - minimumValue,profit);
        }
        
        return profit;
    }
};