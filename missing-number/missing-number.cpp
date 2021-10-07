class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int maxNumber = nums.size(), sum = 0;
        
        for(auto it : nums) {
            sum += it;
        }
        
        int sumOfNaturalNumbers = maxNumber * (maxNumber + 1) / 2;
        
        return sumOfNaturalNumbers - sum;
        
    }
};