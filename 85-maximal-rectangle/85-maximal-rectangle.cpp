class Solution {
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(heights.size() == 0) return 0;
        int* left,*right;
        left = new int[n];
        right = new int[n];
        stack<int> stk;
        left[0] = 0;
        right[n-1] = n-1;
        
        
        //for left limit....
        
        stk.push(0);
        for(int i = 1 ;i < n; i++) {
            int temp ;
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if(!stk.empty())
              temp = stk.top();
            if(!stk.empty())
              left[i] = temp + 1;
            else
              left[i] = 0;
            stk.push(i);
        }
        
        while(!stk.empty())
            stk.pop();
        
        //for right limit...
        
       stk.push(n-1);
        for(int i = n-2 ;i >= 0; i--) {
            int temp ;
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            cout << endl;
            if(!stk.empty())
              temp = stk.top();
            if(!stk.empty())
              right[i] = temp - 1;
            else
              right[i] = n-1;
            stk.push(i);
        }
        
        
        
        int maxArea = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            int curr = heights[i] * (right[i]-left[i]+1);
            maxArea = max(curr,maxArea);
        }
        return maxArea;
    }
    
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0) return 0;
        
        
        int n = matrix.size();
        int m = matrix[0].size();
        //cout << "n = " << n << " m = " << m << endl;
        vector<vector<int>> mat(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                mat[i][j] = (matrix[i][j] == '1') ? 1 : 0;
            }
        }
        for(int i = 0 ; i < m ; i++) {
            int sum = 0;
            for(int j = 0 ; j < n; j++) {
                if(mat[j][i])
                 sum = mat[j][i] + sum; 
                else
                    sum = 0;
                mat[j][i] = sum;
            }
        }
        vector<int> heights(m,0);
        int maxArea = INT_MIN;
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m; j++) {
                heights[j] = mat[i][j];
                //cout << mat[i][j] << " ";
            }
            cout << endl;
            int curr = largestRectangleArea(heights);
            //cout << " curr = " << curr << endl;
            maxArea = max(maxArea,curr);
        }
        return maxArea;
    }
};