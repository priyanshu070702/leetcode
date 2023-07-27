//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solveMemo(int n, int m, string s1, string s2, int i, int j, vector<vector<int>>&dp){
        if(i==n||j==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int len=0;
        if(s1[i]==s2[j]){
            len=1+solveMemo(n,m,s1,s2,i+1,j+1,dp);
        }
        else{
            len=max(solveMemo(n,m,s1,s2,i+1,j,dp),solveMemo(n,m,s1,s2,i,j+1,dp));
        }
        return dp[i][j]=len;
    }
    int solveTab(int n, int m, string s1, string s2){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int len=0;
                if(s1[i]==s2[j]){
                    len=1+dp[i+1][j+1];
                } 
                else{
                    len=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=len;
            }
        }
        return dp[0][0];
    }
    int lcs(int n, int m, string s1, string s2)
    {
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solveMemo(n,m,s1,s2,0,0,dp);
        return solveTab(n,m,s1,s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends