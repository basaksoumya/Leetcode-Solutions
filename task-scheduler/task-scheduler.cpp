class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26], l = tasks.size();
        
        if(n == 0) return l;
        memset(freq,0,sizeof(freq));
        
        for(int i = 0 ; i < l ; i++) {
            freq[tasks[i] - 'A']++;
        }
        
        int maxVal = INT_MIN, maxSameVal = 0;
        
        for(int i = 0 ; i < 26 ; i++) {
            maxVal = max(maxVal,freq[i]);
        }
        
        for(int i = 0 ; i < 26 ; i++) 
            if(maxVal == freq[i])
                maxSameVal++;
        
        int ans = (maxVal - 1) * (n + 1) + maxSameVal;
        
        return max(l,ans);
    }
};