class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        n = abs(n);
        double pow1 = log2(n);
        int pow2 = log2(n);
        
        return pow1 == pow2 ? true : false;
    }
};