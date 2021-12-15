class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size(),i = 0;
        
        if(n == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        
        while(i < n && newInterval[0] > intervals[i][1]) {
            ans.push_back(intervals[i++]);
        }
        
        while(i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i < n) {
            ans.push_back(intervals[i++]);
        }
        
        return ans;
    }
};