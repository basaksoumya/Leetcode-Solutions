class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) 
            return 0;
        
        int left = 0, right = n-1,mid;
        
        while(left <= right) {
            
            mid = left + (right - left) / 2;
            
            int leftVal,rightVal;
            
            leftVal = (mid == 0) ? INT_MIN : nums[mid-1];
            rightVal = (mid == n-1) ? INT_MIN : nums[mid+1];
            
            if(nums[mid] > rightVal && nums[mid] > leftVal) {
                return mid;
            }
            else if(nums[mid] < leftVal) {
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
    
        return mid;
    }
};