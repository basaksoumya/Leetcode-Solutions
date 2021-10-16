class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> leftProduct(n,1),rightProduct(n,1),answer(n,1);
        leftProduct[0] = nums[0],rightProduct[n-1] = nums[n-1];
        
        for(int i = 1 ; i < n ; i++)
            leftProduct[i] = leftProduct[i-1] * nums[i];
        
        for(int i = n-2 ; i >= 0 ; i--)
            rightProduct[i] = rightProduct[i+1] * nums[i];
        
        answer[0] = rightProduct[1];
        answer[n-1] = leftProduct[n-2];
        for(int i = 0 ; i < n ; i++) {
            if(i != 0 && i != n-1) {
                answer[i] = leftProduct[i-1] * rightProduct[i+1];
            }
        }
        return answer;
    }
};