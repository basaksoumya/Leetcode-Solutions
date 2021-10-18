class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        int i=0;
        
        while(i<n-2){
            
            if(i > 0 && nums[i]==nums[i-1]) {
                i++;
                continue;
            }
            int first=i+1;
            int last=n-1;
            
            int t=-nums[i];
            while(first<last){
                
                if(nums[first] + nums[last]==t){
                    
                    while (first<last && nums[first] == nums[first+1]) 
                        first++;
                    // to handle duplicates
                    while (first<last && nums[last] == nums[last-1]) 
                        last--;
                    ans.push_back({nums[i],nums[first],nums[last]});
                    first++;
                    last--;
                }
                else if(nums[first]+nums[last] < t){
                    first++;
                }
                else{
                    last--;
                }
                
            }
            
            i++;
        }
        
        
        return ans;
    }
};