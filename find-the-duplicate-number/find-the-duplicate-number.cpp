class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(),ans = 0;
        
        for(int i = 0 ; i < n ; i++) {
            int curr = abs(nums[i]);
            
            if(nums[curr] < 0) {
                ans = abs(nums[i]);
                break;
            }
            nums[curr] *= -1;
        }
        
        for(auto it : nums)
            it  = abs(it);
        
        return ans;
    }
};