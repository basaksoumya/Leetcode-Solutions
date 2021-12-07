class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(),ans = 1;
        
        int* rightMin = new int[n];
        rightMin[n-1] = arr[n-1]; 
        for(int i = n-2; i >= 0 ; i--) {
            rightMin[i] = min(arr[i],rightMin[i+1]);
        }
        int leftMax = arr[0];
        
        for(int i = 0 ; i < n-1 ; i++) {
            leftMax = max(arr[i],leftMax);
            
            if(leftMax <= rightMin[i+1]) {
                ans++;
            }
        }
        
        return ans;
    }
};