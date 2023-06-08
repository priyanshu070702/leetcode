class Solution {
public:
    // int func(vector<int>& cost, int n){
    //     if(n==0)return cost[0];
    //     if(n==1)return cost[1];
    //     int res=cost[n]+min(func(cost,n-1),func(cost,n-2));
    //     return res;
    // } 
    // int memo(vector<int>cost, int n, vector<int>&dp){
    //     if(n==0)return cost[0];
    //     if(n==1)return cost[1];
    //     if(dp[n]!=-1)return dp[n];
    //     dp[n]=cost[n]+min(memo(cost,n-1,dp),memo(cost,n-2,dp));
    //     return dp[n];
    // }
    int tabu(vector<int>&cost, int n){
        vector<int>dp(n+1,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //recursion
        // int ans = min(func(cost,n-1),func(cost,n-));
        // return ans;

        //memoization
        // vector<int>dp(n+1,-1);
        // int ans=min(memo(cost,n-1,dp),memo(cost,n-2,dp));
        // return ans;

        //tabulation
        return tabu(cost,n);
    }
};