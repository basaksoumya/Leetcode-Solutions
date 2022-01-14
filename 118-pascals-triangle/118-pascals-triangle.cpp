class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        if(numRows == 0) return arr;
        arr.push_back({1});
        for(int i = 1 ; i < numRows ; i++) {
            vector<int> curr;
            curr.push_back(1);
            for(int j = 1 ; j <= i-1; j++) {
                    curr.push_back(arr[i-1][j] + arr[i - 1][j-1]);
            }
            curr.push_back(1);
            arr.push_back(curr);
        }
        return arr;
    }
};