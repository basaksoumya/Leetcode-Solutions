class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int first = 0,last = n-1,mid;
        
        while(first <= last) {
            mid = (first+last) / 2;
            if(nums[mid] == target) {
                return true;
            }
            else if(nums[mid] >= nums[first]) {
                if(nums[mid] >= target && nums[first] <= target) {
                    last = mid - 1;
                }
                else
                    first = mid + 1;
            }
            else{
                if(nums[mid] <= target && nums[last] >= target) {
                    first = mid + 1;
                }else{
                    last = mid - 1;
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == target) {
                return true;
            }
        }
        
        return false;
    }
};