class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int left = 0, n = citations.size(),right = n-1;
        
        while(left <= right) {
            int mid = (left+right) / 2;
            if(citations[mid] == n - mid) {
                return citations[mid];
            }
            else if(n - mid < citations[mid]) {
                right =  mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return n - left;
    }
};