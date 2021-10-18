class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int diff = INT_MAX, ans = 0;
        sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i < n-2 ; i++) {
            int curr = nums[i];
            int l = i+1, r = n-1;
            
            while(l < r) {
                int first = nums[l],last = nums[r];
                int sum = curr + first + last;
                
                if(diff > abs(sum - target)) {
                    diff = abs(sum - target);
                    ans = sum;
                }
                
                if(sum == target)
                    return sum;
                else if(sum < target)
                    l++;
                else
                    r--;
            }
            
        }
        return ans;
    }
};