class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = n-2 ; i >= 0 ; i--) {
            if(nums[i] == nums[i+1])
                nums[i+1] = INT_MAX;
        }
        int left = 0,right = 0;
        while(right < n) { 
            
            if(nums[right] != INT_MAX) {
                swap(nums[left++],nums[right++]);
            }else {
                right++;
            }
           
        }
        
        int i = 0;
        while(i < n && nums[i] != INT_MAX)
            i++;
        
        return i;
    }
};