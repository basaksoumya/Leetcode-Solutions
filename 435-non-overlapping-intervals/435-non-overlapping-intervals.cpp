bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int ans = -1;      
		if(intervals.size()==0) return 0;       
		sort(intervals.begin(),intervals.end(),comp);
		vector<int> prev= intervals[0];

		for(int j = 0; j < intervals.size() ; j++) {
            vector<int> i = intervals[j];
			if(prev[1]>i[0]) {
				ans++;
			}else prev=i;          
		}
		return ans;             
	}
};