class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k <= 1) return 0;
        
        int left = 0 , right = 0;
        int prod = 1, ans = 0;
        for(right = 0 ; right < n ; right++) {
            prod *= nums[right];
            
            while(prod >= k)
                prod /= nums[left++];
            
            if(prod < k) {
                ans += 1+(right - left);
            }
        }
        return ans;
    }
};