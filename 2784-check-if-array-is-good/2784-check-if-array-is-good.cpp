class Solution {
public:
    bool isGood(vector<int>& nums) {
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
        }
        int n=nums.size();
        if(mx+1!=n)return false;
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==mx)cnt++;
        }
        if(cnt==2)return true;
        return false;
    }
};