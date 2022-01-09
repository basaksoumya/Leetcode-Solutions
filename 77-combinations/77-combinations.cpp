class Solution {
public:
    
    void allCombinations(int index,int n,int k,vector<int> temp,vector<vector<int>> &ans) {
        
        if(k == temp.size()) {
            ans.push_back(temp);
            return;
        }
        
        if(k < 0 || index > n) {
           return; 
        }
        
        for(int i = index; i <= n ; i++) {
            temp.push_back(i);
            allCombinations(i+1,n,k,temp,ans);
            temp.pop_back();
        }
    }
    
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if(k > n)
            return ans;
        int index = 1;
        vector<int> temp;
        allCombinations(index,n,k,temp,ans);
        return ans;
    }
};