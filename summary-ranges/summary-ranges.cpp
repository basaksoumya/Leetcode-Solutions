class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> r;
        
        int n = nums.size();
        
        for(int p = 0,q = 0 ; q < n ; q++) {
            
            if (q+1== n || nums[q+1]!=nums[q]+1) {
                
			    r.emplace_back( p!=q ? to_string(nums[p])+"->"+to_string(nums[q]) : to_string(nums[p]) );
			    p=q+1;
		    }
        }
        return r;
    }
};