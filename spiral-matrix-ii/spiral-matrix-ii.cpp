class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n,vector<int>(n,0));
        int maximum = 1;
        int left = 0,right = n-1,top = 0, down = n-1,dir = 0;
        while(maximum <= n*n) {
            if(dir == 0) {
                for(int i = left; i <= right ; i++) {
                    ans[top][i] = maximum++;
                }
                top++;
                dir += 1;
                dir = dir % 4;
            }
            else if(dir == 1) {
                for(int i = top; i <= down ; i++) {
                    ans[i][right] = maximum++;
                }
                right--;
                dir += 1;
                dir = dir % 4;
            }
            else if(dir == 2) {
                for(int i = right; i >= left ; i--) {
                    ans[down][i] = maximum++;
                }
                down--;
                dir += 1;
                dir = dir % 4;
            }
            else if(dir == 3) {
                for(int i = down; i >= top ; i--) {
                    ans[i][left] = maximum++;
                }
                left++;
                dir += 1;
                dir = dir % 4;
            }
        }
        
        return ans;
    }
};