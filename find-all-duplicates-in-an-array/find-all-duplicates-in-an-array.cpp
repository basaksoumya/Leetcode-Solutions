class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++) {
            int curr = abs(nums[i]) -1;
            if(nums[curr] < 0) {
                ans.push_back(abs(nums[i]));
            }
            nums[curr] *= -1;
        }
        for(auto it : nums)
            it = abs(it);
        
        return ans;
    }
};