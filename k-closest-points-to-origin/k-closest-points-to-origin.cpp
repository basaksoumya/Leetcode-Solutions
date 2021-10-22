class Solution {
public:
    typedef pair<double,vector<int>> pii;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pii> pq;
        vector<vector<int>> ans;
        int size = 0, n = points.size();
        
        if(k == n) return points;
        
        for(int i = 0 ; i < n ; i++) {
            vector<int> curr = points[i];
            double dist = sqrt(curr[0]*curr[0] + curr[1] * curr[1]);
            if(pq.size() < k) {
                pq.push({dist,curr});
            }
            else if(pq.top().first > dist) {
                pq.pop();
                pq.push({dist,curr});
            }
        }
        
        while(pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};