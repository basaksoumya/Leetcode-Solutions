class Solution {
public:
    
    void permuteRecursive(vector<int> &arr,int index,vector<vector<int>> &ans) {
        if(arr.size() - 1 == index) {
            ans.push_back(arr);
        }else {
            for(int i = index ; i < arr.size() ; i++) {
                
                swap(arr[i],arr[index]);
                permuteRecursive(arr,index+1,ans);
                swap(arr[i],arr[index]);
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteRecursive(nums,0,ans);
        return ans;
    }
};