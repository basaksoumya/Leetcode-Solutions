class Solution {
public:
    
    void solution(int index,int k,int n,vector<int> temp,vector<vector<int>> &ans) {
        
        if(k == 0 && n == 0) {
            ans.push_back(temp);
            return;
        }
        
        if(k <= 0 || n <= 0)
            return;
        
        for(int i = index ; i < 10 ; i++) {
            temp.push_back(i);
            solution(i+1,k-1,n-i,temp,ans);
            temp.pop_back();
        }
    }
    
    
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        solution(1,k,n,temp,ans);
        
        return ans;
    }
};