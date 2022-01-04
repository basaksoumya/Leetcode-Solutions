class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jump , maxReach , step , n = nums.size();
        if(nums.size() <= 1)
            return 0;
        
        maxReach = nums[0];
        step = nums[0];
        jump = 1;
        
        for(int i = 1 ; i < n - 1 ; i++) {
            
            maxReach = max(maxReach,i+nums[i]);
            
            step--;
            if(step == 0) {
                jump++;
                step = maxReach - i;    
            }
        }
        return jump;
    }
};