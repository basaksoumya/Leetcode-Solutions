class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> set;
        
        int total = 1 << nums.size();
        
        for(int i = 0 ; i < total ; i++) {
            vector<int> tempAns;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    tempAns.push_back(nums[j]);
                }
            }
            set.insert(tempAns);
        }
        
        for(auto it : set) {
            ans.push_back(it);
        }
        return ans;
    }
};