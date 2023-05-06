class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod=1000000007;
        sort(nums.begin(),nums.end());
        int res=0;
        vector<int>v(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            v[i]=(v[i-1]*2)%mod;
        }
        int low=0,high=nums.size()-1;
        while(low<=high){
            if(nums[low]+nums[high]>target){
                high--;
            }
            else{
                res=(res+v[high-low])%mod;
                low++;
            }
        }
        return res;
    }
};
