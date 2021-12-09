class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n) {
            int sum = 0;
            while(n) {
               int digit = n % 10;
               sum += digit*digit;
               n = (n - digit) / 10; 
            }
            n = sum;
            if(set.find(n) != set.end())
                break;
            set.insert(n);
            if(n == 1)
                return true;
        }
        return false;
    }
};