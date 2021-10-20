class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int left = 0, right = n-1,mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            int leftVal,rightVal;
            leftVal = (mid == 0) ? nums[n-1] : nums[mid-1];
            rightVal = (mid == n-1) ? nums[0] : nums[mid + 1];
            if(nums[mid] < rightVal && nums[mid] < leftVal) {
                return nums[mid];
            }
            else if(nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return nums[mid];
    }
};