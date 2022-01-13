class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxi = nums[0],n = nums.size(),index = 0;
        int start = -1, end = -1, len = 0;
        
        for(int i = 0 ; i <= n-1 ; i++) {
            if(nums[i] < maxi && start == -1) {
                start = index;
            }
            if(nums[i] < maxi) {
                end = i;
            }
            if(nums[i] > maxi) {
                index = i;
                maxi = nums[i];
            }
        }
        len = end - start + 1;
        int mini = nums[n-1];
        for(int i = n-1 ; i >= 0 ; i--) {
            if(nums[i] < mini && end == -1) {
                end = index;
            }
            if(nums[i] > mini) {
                start = i;
            }
            if(nums[i] < mini) {
                index = i;
                mini = nums[i];
            }
        }
        len = max(len,end-start+1);
        cout << "start = " << start << " end = " << end << endl;
        return start != -1 ? end - start + 1 : 0;
    }
};