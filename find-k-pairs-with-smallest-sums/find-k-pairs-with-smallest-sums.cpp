class Solution {
public:
    
    typedef pair<int, pair<int, int>> pii;
        
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        set<pair<int,int>> set;
        
        pq.push({nums1[0]+nums2[0],{0,0}});
        int flag = 1;
        while(k-- && flag) {
            pii curr = pq.top();
            pq.pop();
            int i = curr.second.first, j = curr.second.second;
            ans.push_back({nums1[i],nums2[j]});
            flag = 0;
            if(i+1 < nums1.size()) {
                
                if(set.find({i+1,j}) == set.end()) {
                    pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                    set.insert({i+1,j});
                }
                flag = 1;
                
            }
            
            if(j+1 < nums2.size()) {
                
                if(set.find({i,j+1}) == set.end()) {
                    pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                    set.insert({i,j+1});
                }
                flag = 1;
            }
        }
        
        return ans;
    }
};