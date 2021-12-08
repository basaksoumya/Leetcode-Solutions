class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mapt;
        
        for(int i = 0 ; i < t.size() ; i++) {
            mapt[t[i]]++;
        }
        
        int ans = 0,left = 0 , right = 0, n = s.size();
        int total = t.size(), count = 0, ansx = 0,ansy = 0;
        int length = 0;
        unordered_map<char,int> temp;
        while(1) {
            
            bool flag = false;
            while(right < n && count < total) {
                char c = s[right++];
                temp[c]++;
                if(mapt[c] >= temp[c])
                    count++;
                flag = true;
            }
           // cout << "right = " << right << endl;
            while(count >= total && left <= right) {
                
                if(count >= total && (length == 0 || length > right - left + 1)) {
                    ansx = left;
                    ansy = right;
                    length = right - left + 1;
                }
                
                char c = s[left];
                temp[c]--;
                
                if(temp[c] < mapt[c])
                    count--;
                if(temp[c] <= 0)
                    temp.erase(c);
                
                flag = true;
                left++;
            }
            //cout << "left = " << left << endl;
            if(!flag)
                break;
            
        }
        
        //cout << " length = " << length << endl;
        if(!length)
            return "";
        else{
            string ans = "";
            while(ansx < ansy) {
                ans += s[ansx++];
            }
            return ans;
        }
        
    }
};