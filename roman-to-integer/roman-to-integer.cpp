class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map;
        int n = s.size();
        int result = 0;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        
        for(int i = 0 ; i < s.size() ; i++) {
            
            switch (s[i]) {
                case 'I':
                    if(i+1 < n && (s[i+1] == 'V' || s[i+1] == 'X')) {
                        if(s[i+1] == 'V')
                            result += 4;
                        else
                            result += 9;
                        i++;
                    }
                    else
                        result += map['I'];
                        
                    break;
                case 'V':
                    result += map['V'];
                    
                    break;
                case 'X':
                    if(i+1 < n && (s[i+1] == 'L' || s[i+1] == 'C')) {
                        if(s[i+1] == 'L')
                            result += 40;
                        else
                            result += 90;
                        i++;
                    }
                    else
                        result += map['X'];
                    
                    break;
                case 'L':
                    result += map['L'];
                    break;
                case 'C':
                    if(i+1 < n && (s[i+1] == 'D' || s[i+1] == 'M')) {
                        if(s[i+1] == 'D')
                            result += 400;
                        else
                            result += 900;
                        i++;
                    }
                    else
                        result += map['C'];
                    break;
                case 'D':
                    result += map['D'];
                    break;
                case 'M':
                    result += map['M'];
                    break;
            }
        }
        return result;
    }
};