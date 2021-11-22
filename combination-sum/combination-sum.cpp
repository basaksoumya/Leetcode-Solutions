class Solution {
public:
    
        
    
    void combinationSumRecursive(vector<int> &candidates,int target,vector<vector<int>> &ans,vector<int> curr,int index) {
        
        if(target < 0)
            return;
        
        if(candidates.size() == index) {
            
            if(target == 0) {
                ans.push_back(curr);
            }
            return;
        }
        
        if(candidates[index] <= target) {
            curr.push_back(candidates[index]);
            combinationSumRecursive(candidates,target - candidates[index],ans,curr,index);
            curr.pop_back();
        }
        
        combinationSumRecursive(candidates,target,ans,curr,index+1);
    }
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        
        if(target == 0)
            return ans;
        vector<int> curr;
        int index = 0;
        combinationSumRecursive(candidates,target,ans,curr,index);
        return ans;
    }

};