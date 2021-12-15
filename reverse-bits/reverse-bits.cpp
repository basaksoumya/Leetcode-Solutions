class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bool flag = false;
        int ans = 0;
        for(int i = 31,j = 0 ; i >= 0 ; i--,j++) {
            int mask = 1 << i;
            if(flag) {
                if((mask & n) != 0) {
                    mask = 1 << j;
                    ans |= mask;
                }
            }
            else {
                if((mask & n) != 0) {
                    mask = 1 << j;
                    ans |= mask;
                    flag = true;
                }
            }
        }
        
        return ans;
    }
};