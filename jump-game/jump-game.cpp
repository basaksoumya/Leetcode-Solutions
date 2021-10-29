class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),maxReach = nums[0],step = nums[0];
        
        for(int i = 0 ; i < n ; i++) {
            
            if(i == n-1)
                break;
            
            if(nums[0] == 0)
            return false;
            
            maxReach = max(i+nums[i],maxReach);
            step--;
            if(step == 0) {
                if(maxReach <= i)
                    return false;
                step = maxReach - i;
            }
        }
        
        if(maxReach >= n-1)
            return true;
        return false;
    }
};