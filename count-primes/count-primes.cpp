class Solution {
public:
    int countPrimes(int n) {
        vector<bool> arr(n,true);
        int count = 0;
        for(int i = 2 ; i <= sqrt(n) ; i++) {
            if(arr[i] == true) {
                for(int j = i*i ; j < n ; j=j+i) {
                    arr[j] = false;
                }
            }
        }
        
        for(int i = 2 ; i < n ; i++) {
            if(arr[i])
                count++;
        }
        return count;
    }
};