class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        vector<int> res;
        if(s.size() < len*words.size())
            return res;
        
        unordered_map<string,int> wordMap;
        
        for(auto it : words){
            wordMap[it]++;
        }
        
        
        for(int i = 0 ; i <= s.size() - len*words.size() ; i++) {
            unordered_map<string,int> temp;
            for(int j = i ; j < i+(len*words.size()) ; j += len) {
                
                string curr = s.substr(j,len);
                if(wordMap.find(curr) == wordMap.end()) {
                    break;
                }
                
                temp[curr]++;
                if(temp[curr] > wordMap[curr])
                    break;
            }
            
            if(wordMap == temp) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};