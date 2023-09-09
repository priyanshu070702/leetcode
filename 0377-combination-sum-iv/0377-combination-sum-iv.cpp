class Solution {
public:
    int solveRec(int n, vector<int>nums, int target, int idx, vector<vector<int>>&dp){
        if(target==0){
            return 1;
        }
        if(target<0 || idx>=n)return 0;
        if(dp[target][idx]!=-1)return dp[target][idx];
        
        int take=0;
        if(nums[idx]<=target){
            take=solveRec(n,nums,target-nums[idx],0,dp);
        }
        int notTake=solveRec(n,nums,target,idx+1,dp);
        
        return dp[target][idx]=take+notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(target+1,vector<int>(n,-1));
        return solveRec(n,nums,target,0,dp);
    }
};