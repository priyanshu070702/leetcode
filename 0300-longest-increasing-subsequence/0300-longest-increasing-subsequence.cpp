class Solution {
public:
    int solveMemo(vector<int>nums, int n, int curr, int prev, vector<vector<int>>&dp){
        if(curr==n)return 0;
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        //include
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            include=1+solveMemo(nums,n,curr+1,curr,dp);
        }
        //exclude
        int exclude=solveMemo(nums,n,curr+1,prev,dp);
        return dp[curr][prev+1]=max(include,exclude);
    }
    int solveTab(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                //include
                int include=0;
                if(prev==-1 || nums[curr]>nums[prev]){
                   include=1+dp[curr+1][curr+1];
                }
                //exclude
                int exclude=dp[curr+1][prev+1];
                
                dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solveMemo(nums,n,0,-1,dp);
        return solveTab(nums);
    }
};