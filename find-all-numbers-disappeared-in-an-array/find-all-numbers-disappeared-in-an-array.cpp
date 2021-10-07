class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int maxNumber = INT_MIN, n = nums.size();
        for(int i = 0; i < n ; i++) {
            maxNumber = max(maxNumber,nums[i]);
        }
        maxNumber++;
        for(int i = 0 ; i < n ; i++) {
              nums[(nums[i]%maxNumber)-1] += maxNumber;
        }
        vector<int> ans;
        for(int i = 1; i <= n ; i++) {
            if(nums[i-1]/maxNumber == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};