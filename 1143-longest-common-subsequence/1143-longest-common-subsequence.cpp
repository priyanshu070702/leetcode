class Solution {
public:
    int recSolve(string text1,string text2,int n,int m,int i,int j){
        if(i>=n || j>=m){
            return 0;
        }
        int ans;
        if(text1[i]==text2[j]){
            ans=1+recSolve(text1,text2,n,m,i+1,j+1);
        }
        else{
            ans=max(recSolve(text1,text2,n,m,i+1,j),recSolve(text1,text2,n,m,i,j+1));
        }
        return ans;
    }
    
     int recMemo(string text1,string text2,int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1+recMemo(text1,text2,n,m,i+1,j+1,dp);
        }
        else{
            ans=max(recMemo(text1,text2,n,m,i+1,j,dp),recMemo(text1,text2,n,m,i,j+1,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    
    int solveTab(string text1, string text2, int n, int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                 if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                 }
                 else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        //return recSolve(text1,text2,n,m,0,0);
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return recMemo(text1,text2,n,m,0,0,dp);
        return solveTab(text1,text2,n,m);
    }
};