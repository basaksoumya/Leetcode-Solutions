class Solution {
public:
    typedef pair<int,int> pii;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size(),size = k;
        for(int i = 0 ; i < n ; i++)
            mp[nums[i]]++;
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(auto it : mp) {
            if(size-- > 0){
                pq.push({it.second,it.first});
            }
            else if(pq.top().first < it.second) {
                pq.pop();
                pq.push({it.second,it.first});
            }
        }
        
        vector<int> ans;
        
        while(pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};