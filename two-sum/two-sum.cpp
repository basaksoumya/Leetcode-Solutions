class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0 ; i < n; i++) {
            mp.insert({nums[i],i});
            if(mp.find(target - nums[i]) != mp.end() && mp[target-nums[i]] != i) {
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
            }
        }
        return ans;
    }
};