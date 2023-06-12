class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>s;
        if(nums.size()==1){
            s.push_back(to_string(nums[0]));
            return s;
        }
        int i=0;
        while(i<nums.size()){
            int l=i;
            int r=i;
            while(r+1<nums.size() && nums[r+1]==nums[r]+1){
                r++;
            }
            if(r>l){
                s.push_back(to_string(nums[l])+"->"+to_string(nums[r]));
            }
            else{
                s.push_back(to_string(nums[r]));
            }
            i=r+1;
        }
        return s;
    }
};