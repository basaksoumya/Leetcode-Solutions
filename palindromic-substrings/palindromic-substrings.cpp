class Solution {
public:
    
    void countPalindrome(string &s,int i,int j,int &count) {
        int n = s.size();
        while(i >= 0 && j < n && s[i] == s[j]) {
            count++;
            i--,j++;
        }
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        
        for(int i = 0 ; i < n ; i++) {
            countPalindrome(s,i,i,count);
            if(i + 1 < n)
              countPalindrome(s,i,i+1,count);
        }
        
        return count;
    }
};