class Solution {
public:
    int solveRec(string s1, string s2, int i, int j, int l1, int l2, vector<vector<int>>&dp){
        if(i==l1 && j==l2)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int cost=0;
        if(i==l1){
            cost+=s2[j]+solveRec(s1,s2,i,j+1,l1,l2,dp);
        }
        else if(j==l2){
            cost+=s1[i]+solveRec(s1,s2,i+1,j,l1,l2,dp);
        }
        
        //if both char are equal1
        else if(s1[i]==s2[j]){
            cost+=solveRec(s1,s2,i+1,j+1,l1,l2,dp);
        }
        //if they are not same and deletion is required
        else{
            int take_first=s1[i]+solveRec(s1,s2,i+1,j,l1,l2,dp);
            int take_second=s2[j]+solveRec(s1,s2,i,j+1,l1,l2,dp);
        
            cost+=min(take_first,take_second);
        }
        return dp[i][j] = cost;
    }
    int solveTab(string s1,string s2){
        int l1=s1.length(),l2=s2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        dp[l1][l2] = 0;
        for (int i = l1 - 1; i >= 0; --i) {
            dp[i][l2] = dp[i + 1][l2] + s1[i];
        }

        for (int j = l2 - 1; j >= 0; --j) {
            dp[l1][j] = dp[l1][j + 1] + s2[j];
        }
        for(int i=l1-1;i>=0;i--){
            for(int j=l2-1;j>=0;j--){
                //if both char are equal1
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                //if they are not same and deletion is required
                else{
                    int take_first=s1[i]+dp[i+1][j];
                    int take_second=s2[j]+dp[i][j+1];

                    dp[i][j]=min(take_first,take_second);
                }
            }
        }
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        int l1=s1.length(),l2=s2.length();
        // vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        // return solveRec(s1,s2,0,0,l1,l2,dp);
        return solveTab(s1,s2);
    }
};