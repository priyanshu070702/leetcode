class Solution {
public:
    bool isSafe(int i, int j, int m,int n){
        if(i>=0 && i<=m &&j>=0 && j<=n){
            return true;
        }
        return false;
    }
    int solveRec(int i, int j, int m, int n){
        if(i==m && j==n){
            return 1;
        }
        //down
        int down=0;
        if(isSafe(i+1,j,m,n)){
            down+=solveRec(i+1,j,m,n);
        }
        //right;
        int right=0;
        if(isSafe(i,j+1,m,n)){
            right=solveRec(i,j+1,m,n);
        }
        return right+down;
    } 
    
    int solveMemo(int i, int j, int m, int n, vector<vector<int>>&dp){
        if(i==m && j==n){
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        //down
        int down=0;
        if(isSafe(i+1,j,m,n)){
            down+=solveMemo(i+1,j,m,n,dp);
        }
        //right;
        int right=0;
        if(isSafe(i,j+1,m,n)){
            right=solveMemo(i,j+1,m,n,dp);
        }
        return dp[i][j]=right+down;
    }
    
    int solveTab(int m, int n){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1]=1;
        for(int j=0;j<n;j++){
            dp[m-1][j]=1;
        }
        for(int i=0;i<m;i++){
            dp[i][n-1]=1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
    
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solveMemo(0,0,m-1,n-1,dp);
        return solveTab(m,n);
    }
};