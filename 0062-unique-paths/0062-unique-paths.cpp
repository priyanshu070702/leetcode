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
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solveMemo(0,0,m-1,n-1,dp);
    }
};