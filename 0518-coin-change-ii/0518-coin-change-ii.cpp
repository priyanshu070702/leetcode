class Solution {
public:
    int solveRec(int amount, vector<int>&coins, int idx, vector<vector<int>>&dp){
        if(amount<0 || idx>=coins.size())return 0;
        if(amount==0)return 1;
        if(dp[amount][idx]!=-1)return dp[amount][idx];
        //take
        int take=0;
        if(coins[idx]<=amount){
            take=solveRec(amount-coins[idx], coins, idx, dp);
        }
        //nottake
        int not_take=solveRec(amount, coins, idx+1, dp);
        
        return dp[amount][idx]=(take+not_take);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1, vector<int>(coins.size(),-1));
        return solveRec(amount, coins, 0, dp);
    }
};