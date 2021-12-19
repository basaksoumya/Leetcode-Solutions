class Solution {
public:
    
    void solution(vector<int> &nums,int k,int index,vector<int> &temp,vector<vector<int>> &ans) {
        if(k == 0) {
            ans.push_back(temp);
            return;
        }
        else if(k < 0)
            return;
        
        
        
        for(int i = index ; i < nums.size() ; i++) {
            if(nums[i] > k) break;
            if(i > index && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            solution(nums,k-nums[i],i+1,temp,ans);
            temp.pop_back();
        }
    }
    
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>  ans;
        
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solution(candidates,target,0,temp,ans);
            
        return ans;
    }
};