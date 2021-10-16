class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1;
        bool ans = true;
        int count = 0;
        while(i >= 0) {
            if(s[i] == '#'){
                count++;
                i--;
                continue;
            }
            if(count > 0 ) {
                s[i] = '#';
                count--;
            }
            i--;
        }
        i = t.size() - 1, count = 0;
        while(i >= 0) {
            if(t[i] == '#'){
                count++;
                i--;
                continue;
            }
            if(count > 0 ) {
                t[i] = '#';
                count--;
            }
            i--;
        }
        int j = 0;
        i = 0;
        //cout << "t size = " << t.size() << ", s size = " << s.size() << endl;
        while(i < s.size() || j < t.size()) {
            //cout << "s[" << i << "] = " << s[i] << endl;
            //cout << "t[" << j << "] = " << t[j] << endl;
            if(s[i] == '#') {
                i++;
                continue;
            }
            if(t[j] == '#') {
                j++;
                continue;
            }
            if(s[i] != t[j]){
                ans = false;
                break;
            }
            i++,j++;
        }
        
        return ans;
    }
};