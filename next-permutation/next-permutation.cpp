class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakpoint;
        int flag = 1;
        
        if(n == 0 || n == 1)
            return;
            
        for(int i = n-2 ; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                breakpoint = i;
                flag = 0;
                break;
            }
        }
        
        if(flag) {
            reverse(nums.begin(),nums.end());
            return;
        }
        int greater;
        
        for(int i = n -1 ; i >= 0 ; i--) {
            if(nums[breakpoint] < nums[i]) {
                greater = i;
                break;
            }
        }
        
        int temp = nums[greater];
        nums[greater] = nums[breakpoint];
        nums[breakpoint] = temp;
        breakpoint++;
        
        reverse(nums.begin()+breakpoint,nums.end());
    }
};