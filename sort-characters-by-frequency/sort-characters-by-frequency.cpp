class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        if(n == 0 || n == 1) 
            return s;
        priority_queue<pair<int,char>> maxHeap;
        unordered_map<char,int> map;
        for(int i = 0 ; i < n ; i++) {
            map[s[i]]++;
        }
        for(auto it : map) {
            maxHeap.push({it.second,it.first});
        }
        string ans = "";
        while(!maxHeap.empty()) {
            char curr = maxHeap.top().second;
            int freq = maxHeap.top().first;
            maxHeap.pop();
            while(freq--)
              ans.push_back(curr);
        }
        return ans;
    }
};