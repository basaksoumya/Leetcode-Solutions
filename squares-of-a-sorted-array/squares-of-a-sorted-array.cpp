class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> num(nums.size(),0);
        
        for(int i = 0 ; i < nums.size() ; i++) {
            nums[i] = abs(nums[i]);
        }
        
        int lo = 0 , hi = nums.size() - 1, k = num.size() - 1;
        
        while(lo <= hi ) {
            
            if(nums[lo] >= nums[hi]) {
                num[k--] = nums[lo++];
            }
            else{
                num[k--] = nums[hi--];
            }
        }
        
        for(int i = 0 ; i < num.size() ; i++) {
            num[i] = num[i] * num[i];
        }
        
        return num;
    }
};