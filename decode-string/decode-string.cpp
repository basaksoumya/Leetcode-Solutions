class Solution {

    
    string decodeStringRecursive(string &s,int &i) {
        
        string result = "";
        while(i < s.size() && s[i] != ']') {
            if(isdigit(s[i])) {
                int number = 0;
                
                while( i < s.size() && isdigit(s[i])) {
                    number = number * 10 + (s[i++] - '0');
                }
                i++;
                string r = decodeStringRecursive(s,i);
                
                while(number--) {
                    result += r;
                }
                i++;
            }
            else{
                result += s[i++];
            }
        }
        
        return result;
    }
    
    
public:
    string decodeString(string s) {
        int i = 0;
        string ans = decodeStringRecursive(s,i);
        return ans;
    }
};