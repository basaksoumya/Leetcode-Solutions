class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSoFar = INT_MIN;
        int curr = 0;
        for(int i = 0 ; i < n ; i++) {
            curr += nums[i];
            curr = max(curr,nums[i]);
            if(curr > maxSoFar)
                maxSoFar = curr;
        }
        return maxSoFar;
    }
};