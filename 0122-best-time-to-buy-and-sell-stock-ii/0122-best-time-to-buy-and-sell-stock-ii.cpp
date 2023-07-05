class Solution {
public:
    int stockMemo(vector<int>&prices, int n, int index, bool buy, vector<vector<int>>&dp){
        if(index>=n){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy==1){
            profit=max((-prices[index]+stockMemo(prices,n,index+1,0,dp)),
                       stockMemo(prices,n,index+1,1,dp));
        }
        else if(buy==0){
            profit=max((prices[index]+stockMemo(prices,n,index+1,1,dp)),
                       stockMemo(prices,n,index+1,0,dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return stockMemo(prices,n,0,1,dp);
    }
};