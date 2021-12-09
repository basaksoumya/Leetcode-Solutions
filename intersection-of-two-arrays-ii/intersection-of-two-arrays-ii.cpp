class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map1,map2;
        vector<int> ans;
        for(int i = 0 ; i < nums1.size() ; i++) {
            map1[nums1[i]]++;
        }
        
        for(int i = 0 ; i < nums2.size() ; i++) {
            map2[nums2[i]]++;
        }
        
        for(auto it : map1) {
            if(map2.find(it.first) != map2.end()) {
                int k = min(map2[it.first],map1[it.first]);
                while(k--)
                    ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};