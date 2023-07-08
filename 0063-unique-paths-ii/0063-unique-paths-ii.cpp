class Solution {
public:
    bool isSafe(int i,int j, int n, int m){
        if(i>=0 && i<=n && j>=0 && j<=m){
            return true;
        }
        return false;
    }
    int solveMemo(int i,int j, int n, int m, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i==n && j==m)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        //int right
        int right=0;
        if(isSafe(i+1,j,n,m)==true && grid[i+1][j]!=1){
            right+=solveMemo(i+1,j,n,m,grid,dp);
        }
        //down
        int down=0;
        if(isSafe(i,j+1,n,m)==true && grid[i][j+1]!=1){
            down+=solveMemo(i,j+1,n,m,grid,dp);
        }
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1)return 0;
        if(n==1 || m==1){
            if(obstacleGrid[0][0]==0)return 1;
            else return 0;
        }
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solveMemo(0,0,n-1,m-1,obstacleGrid,dp);
    }
};