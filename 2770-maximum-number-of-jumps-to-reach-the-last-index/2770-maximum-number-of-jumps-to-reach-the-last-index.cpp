class Solution {
public:
    int solveRec(vector<int>&nums, int target, int n, int idx, vector<int>&dp){
        if(idx>=n-1)return 0;
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int mx=INT_MIN;
        for(int i=idx+1;i<n;i++){
            if(nums[i]-nums[idx]<=target && nums[i]-nums[idx]>=(-target)){
                mx=max(mx,1+solveRec(nums,target,n,i,dp));
            }
        }
        return dp[idx] = mx;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans=solveRec(nums,target,n,0,dp);
        if(ans>0)return ans;
        return -1;
    }
};