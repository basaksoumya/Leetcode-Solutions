// bool comp(vector<int> &a,vector<int> &b) {
// 	return a[1]<b[1];
// }
// class Solution {
// public:
// 	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
// 		int ans = 0;      
// 		if(intervals.size()==0) return 0;       
// 		sort(intervals.begin(),intervals.end(),comp);
// 		vector<int> prev= intervals[0];

// 		for(int j = 1; j < intervals.size() ; j++) {
//             vector<int> i = intervals[j];
// 			if(prev[1]>i[0]) {
// 				ans++;
// 			}else prev=i;          
// 		}
// 		return ans;             
// 	}
// };

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //first sort the intervals
        sort(intervals.begin(),intervals.end());
        
        //find the overlapping intervals and greeedily remove a interval
        int count=0;
        int i=0;
        int j=1;
        //we use to pointers to compare two intervals
        int n=intervals.size();
        while(j<n){
            //compare i and j
            if(intervals[i][1]<=intervals[j][0])
            {
                //if i and j intervals are not overlapping
                i=j;
                j++;
            }
            else if(intervals[i][1]>=intervals[j][1])
            {
                //if j interval is completely overlapped in i
                //and i interval size is greater than j
                //it is better to reemove i  interval
                count+=1;
                i=j;
                j++;
            }
            else if(intervals[i][1]>intervals[j][0])
            {
                //if j interval is overlapping only some portion of i
                //it is better to remove j
                count+=1;
                j++;
            }
        }
        return count;
    }
};