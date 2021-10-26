class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int maxsofar = nums[0];
        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] < 0) {
                int c = maxi;
                maxi = mini;
                mini = c;
            }
            maxi = max(nums[i],nums[i]*maxi);
            mini = min(nums[i],nums[i]*mini);
            maxsofar = max(maxsofar, maxi);
        }
        return maxsofar;
    }
};