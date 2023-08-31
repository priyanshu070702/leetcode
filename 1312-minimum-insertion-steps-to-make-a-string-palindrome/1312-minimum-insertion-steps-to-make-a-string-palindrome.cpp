class Solution {
public:
    int solveRec(string A, string B, int n, int i, int j,vector<vector<int>>&dp){
        if(i>=n || j>=n)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=0;
        if(A[i]==B[j]){
            ans=1+solveRec(A,B,n,i+1,j+1,dp);
        }
        else{
            ans=max(solveRec(A,B,n,i+1,j,dp),solveRec(A,B,n,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int solveTab(string A, string B){
        int n=A.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int ans=0;
                if(A[i]==B[j]){
                    ans=1+dp[i+1][j+1];
                }
                else{
                    ans=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int minInsertions(string s) {
        string B=s;
        reverse(B.begin(),B.end());
        int n=B.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int st=solveTab(s,B);
        return n-st;
    }
};