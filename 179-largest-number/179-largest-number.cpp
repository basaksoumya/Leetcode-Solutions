class Solution {
public:
    
    
    
    
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(),nums.end(),[](int x,int y){
        std::string xy = to_string(x) + to_string(y);
        std::string yx = to_string(y) + to_string(x);
       // return xy.compare(yx) ? 1 : 0;
        if(xy.compare(yx) == 0) return 0;
        else{
            return xy > yx ? 1 : 0;
        }
    });
        std::string str = "";
        for(auto it : nums){
            str += to_string(it);
        }
        if(str[0] == '0') str = '0';
        return str;
    }
};