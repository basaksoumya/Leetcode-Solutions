class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0,majorityElement = 0;
        
        for(int i = 0 ; i < nums.size() ; i++) {
            if(count == 0) {
                majorityElement = nums[i];
            }
            if(nums[i] == majorityElement) {
                count++;
            }
            else{
                count--;
            }
        }
        return majorityElement;
    }
};