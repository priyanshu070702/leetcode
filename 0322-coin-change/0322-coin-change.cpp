class Solution {
public:
    int coinRec(vector<int>&coins, int amount, int idx, int n,         vector<vector<int>>&dp){
        if(idx==n)return 1e9;
        if(amount==0)return 0;
        
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        //take
        int take=INT_MAX;
        if(coins[idx]<=amount){
            take=1+coinRec(coins,amount-coins[idx],idx,n,dp);
        }
        int nottake=coinRec(coins,amount,idx+1,n,dp);
        return dp[idx][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = coinRec(coins, amount, 0, n, dp);
        if(ans==1e9)return -1;
        return ans;
    }
};