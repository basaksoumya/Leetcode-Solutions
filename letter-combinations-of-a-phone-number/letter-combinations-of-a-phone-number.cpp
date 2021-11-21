class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mapping = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        int index = 0;
        letterCombinationsRecursive(ans,digits,"",index,mapping);
        return ans;
    }
    
    void letterCombinationsRecursive(vector<string> &ans,string digits,string curr,int index,vector<string> &mapping) {
        if(digits.size() == index) {
            ans.push_back(curr);
            return;
        }
        else {
            string str = mapping[digits[index] - '2'];
            for(int i = 0 ; i < str.size() ; i++) {
                letterCombinationsRecursive(ans,digits,curr+str[i],index+1,mapping);
            }
        }
    }
};