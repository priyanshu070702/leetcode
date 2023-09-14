//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod=1e9+7;
	public:
	int solveRec(int arr[], int n, int sum, int idx, vector<vector<int>>&dp){
	    if(sum==0)return 1;
	    if(idx>=n)return 0;
	    
	    if(dp[sum][idx]!=-1)return dp[sum][idx];
	    
	    int take=0;
	    if(arr[idx]<=sum){
	        take=solveRec(arr,n,sum-arr[idx],idx+1,dp);
	    }
	    int notTake=solveRec(arr,n,sum,idx+1,dp);
	    
	    return dp[sum][idx]=(take%mod+notTake%mod)%mod;
	}
	int solveTab(int arr[], int n, int sum){
	    vector<vector<int>>dp(sum+2,vector<int>(n+1,0));
	    for(int i=0;i<=n;i++){
	        dp[0][i]=1;
	    }
	    for(int i=0;i<=sum;i++){
	        for(int j=n-1;j>=0;j--){
	            int take=0;
        	    if(arr[j]<=i){
        	        take=dp[i-arr[j]][j+1];
        	    }
        	    int notTake=dp[i][j+1];
        	    
        	    dp[i][j]=(take%mod+notTake%mod)%mod;
	        }
	    }
	    return dp[sum][0];
	}
	int perfectSum(int arr[], int n, int sum)
	{
        sort(arr,arr+n);
        // vector<vector<int>>dp(sum+1,vector<int>(n+1,-1));
        // return solveRec(arr,n,sum,0,dp);
        return solveTab(arr, n, sum);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends