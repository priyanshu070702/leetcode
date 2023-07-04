class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //using map
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second==1)return it.first;
        }
        return -1;
    }
};