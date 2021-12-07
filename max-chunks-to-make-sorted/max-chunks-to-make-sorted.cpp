class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), maxi = 0,ans = 0;
        
        for(int i = 0 ; i < n ; i++) {
            maxi = max(maxi,arr[i]);
            
            if(i == maxi)
                ans++;
        }
        
        return ans;
    }
};