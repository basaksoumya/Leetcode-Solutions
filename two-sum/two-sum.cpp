class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>> num;
        
        for(int i = 0 ; i < nums.size() ; i++) {
            num.push_back({nums[i],i});
        }
        
        sort(num.begin(),num.end());
        
        int lo = 0, hi = num.size() - 1;
        
        while(lo < hi) {
            int sum = num[lo].first + num[hi].first;
            
            if(sum == target)
                return {num[lo].second,num[hi].second};
                
            else if(sum > target)
                hi--;
            else
                lo++;
        }
        return {-1,-1};
    }
};