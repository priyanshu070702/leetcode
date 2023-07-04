class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //using map
        // map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp){
        //     if(it.second==1)return it.first;
        // }
        // return -1;
        
        //space optimized
        
        sort(nums.begin(),nums.end());
        int cnt=1;
        int n=nums.size();
        if(n==1)return nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                cnt++;
            }
            else{
                if(cnt==3){
                    cnt=1;
                    if(i==n-1)return nums[n-1];
                }
                else{
                    if(i==1)return nums[0];
                    else return nums[i-1];
                }
            }
        }
        return -1;
    }
};