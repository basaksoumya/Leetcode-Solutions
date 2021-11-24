class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jump , maxReach , step , n = nums.size();
        if(n < 1)
            return 0;
        if(nums.size() == 1)
            return 0;
        
        maxReach = nums[0];
        step = nums[0];
        jump = 1;
        
        for(int i = 1 ; i < n ; i++) {
            
            if(i == n-1)
                return jump;
            
            maxReach = max(maxReach,i+nums[i]);
            
            step--;
            if(step == 0) {
                jump++;
                
                if(i >= maxReach)
                    return -1;
                
                step = maxReach - i;
                
            }
        }
        return -1;
    }
};