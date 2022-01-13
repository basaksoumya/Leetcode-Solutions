class Solution {
public:
    
    int getChild(vector<int>& nums, int i) {
        return (nums[i] + i + nums.size()) % nums.size();
    }
    
    bool hasNoCycle(vector<int>& nums, int i) {
        return nums[i] == 1002;
    }
    
    bool isCycle(vector<int> &nums,int start,int par,int dir) {
        if (hasNoCycle(nums, start)) {
            return false;
        }
        if (par == start) {
            nums[start] = 1002;
            return false;
        }
        
        if (nums[start] == 0) {
            return true;
        }
        
        
        if (nums[start] * dir < 0) {
            return false;
        }
        
        int val = nums[start];
        int child = getChild(nums, start);
        nums[start] = 0;        
        
        if (isCycle(nums, child, start, dir)) {
            return true;
        }
        
        nums[start] = 1002;
        return false;
    }
    
    
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++) {
            if(isCycle(nums,i,-1,nums[i])) {
                return true;
            }
        }
        return false;
    }
};