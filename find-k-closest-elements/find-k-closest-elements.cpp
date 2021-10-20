class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        if(n == k)
            return arr;
        
        if(n < k)
            return {};
        int lo = 0, hi = n-1, mid;
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(arr[mid] == x) 
                break;
            if(arr[mid] > x) 
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        int left,right;
        
        if(n % 2 == 1){
            left = mid;
            right = mid + 1;
        }
        else {
            left = mid -1;
            right = mid;
        }
        vector<int> ans;
        cout << "mid = " << arr[mid] << endl;
        while(left >= 0 && right < n && k > 0) {
            if(abs(arr[left] - x) <= abs(arr[right] - x)) {
               ans.push_back(arr[left]);
                cout << "arr[left] = " << arr[left] << endl;
               left--;
            }
           else{
               ans.push_back(arr[right]);
               cout << "arr[right] = " << arr[right] << endl;
               right++;
           }
            k--;
        }
        while(left >= 0 && k > 0) {
            ans.push_back(arr[left]);
            left--;
            k--;
        }
        while(right < n && k > 0) {
            ans.push_back(arr[right]);
            right++;
            k--;
        }
        
        sort(ans.begin(),ans.end());
        for(auto it : arr)
            cout << it << " ";
        return ans;
    }
};