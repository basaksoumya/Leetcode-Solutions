class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> vec(2,0);
        if(nums.size() == 2)
            return (nums[0]-1)*(nums[1]-1);
        vec[0] = nums[0];
        vec[1] = nums[1];
        sort(vec.begin(),vec.end());
        for(int i = 2 ; i < nums.size() ; i++) {
            if(vec[0] < nums[i]) {
                vec[0] = nums[i];
            }
            sort(vec.begin(),vec.end());
        }
        return (vec[0]-1)*(vec[1]-1);
    }
};