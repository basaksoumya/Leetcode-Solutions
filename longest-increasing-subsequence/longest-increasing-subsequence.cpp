class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int* lis = new int[n];
        for(int i = 0 ; i < n ; i++) {
            lis[i] = 1 ;
            for(int j = 0 ; j < i; j++) {
                if(nums[i] > nums[j] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i ++) {
             if(maxi < lis[i] ) {
                 maxi = max(maxi, lis[i]);
             }
        }
        return maxi;
    }
};