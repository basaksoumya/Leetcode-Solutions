class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i = n-1 ; i >= 0 ; i--) {
            digits[i] = (carry + digits[i]);
            if(digits[i] >= 10) {
                digits[i] = digits[i] % 10;
                carry = 1;
            }else{
                carry = 0;
            }
        }
        if(carry != 1) {
            return digits;
        }
        vector<int> ans(n+1,0);
        ans[0] = 1;
        return ans;
    }
};