class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        
        unordered_map<char,int> mapLeft,mapRight;
        
        for(int i = 0 ; i < n ; i++) {
            if(mapLeft.find(s[i]) != mapLeft.end()) {
                mapLeft[s[i]] = i;
                mapRight[s[i]] = 0;
            }else{
                mapRight[s[i]] = i;
            }
        }
        
        int i = 0;
        int start = 0 , maxi = mapRight[s[0]];
        vector<int> ans;
        
        while(i < n) {
            maxi = max(maxi,mapRight[s[i]]);
            if(maxi == i) {
                ans.push_back(maxi - start+1);
                if(i+1 < n) {
                    maxi = mapRight[s[i+1]];
                    start = i+1;
                }
            }
            i++;
                
        }
        
        return ans;
    }
};