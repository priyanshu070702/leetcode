class Solution {
public:
    int maxMoneyRec(vector<int>nums,int i){
        
        int n=nums.size();
        //base condition
        if(i>=n)return 0;
        //exclude
        int exclude=maxMoneyRec(nums,i+1);
        //include
        int include=nums[i]+maxMoneyRec(nums,i+2);
        
        return max(exclude,include);
        
    }
    int maxMoneyMemo(vector<int>nums, int i, vector<int>&dp){
        int n=nums.size();
        //
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        //exclude
        int exclude=maxMoneyMemo(nums,i+1,dp);
        //include
        int include=nums[i]+maxMoneyMemo(nums,i+2,dp);
        dp[i]=max(exclude,include);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        //recursion
        // int ans=maxMoneyRec(nums,0);
        // return ans;
        
        //memoization
        vector<int>dp(nums.size()+1,-1);
        int ans=maxMoneyMemo(nums,0,dp);
        return ans;
    }
};