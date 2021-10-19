class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0,last = height.size() - 1;
        int maxArea = min(height[first],height[last]) * (last-first);
        while(first < last) {
            if(height[first] < height[last]) {
                first++;
            }
            else{
                last--;
            }
            int currArea = min(height[first],height[last]) * (last-first);
            maxArea = max(maxArea,currArea);
        }
        return maxArea;
    }
};