//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        //bruteforce approach
        // vector<int>v;
        // for(int i=0;i<n;i++){
        //     if(arr[i]==x){
        //         v.push_back(i);
        //         break;
        //     }
        //     if(i==n-1)v.push_back(-1);
        // }
        // for(int i=n-1;i>=0;i--){
        //     if(arr[i]==x){
        //         v.push_back(i);
        //         break;
        //     }
        //     if(i==0)v.push_back(-1);
        // }
        // return v;
        vector<int>v(2,-1);
        int low=0,high=n-1;
        
        int ans_first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==x){
                ans_first=mid;
                high=mid-1;
            }
            else if(arr[mid]>x){
                high=mid-1;
            }
            else if(arr[mid]<x){
                low=mid+1;
            }
        }
        v[0]=ans_first;
        
        int ans_last=-1;
        low=0,high=n-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==x){
                ans_last=mid;
                low=mid+1;
            }
            else if(arr[mid]>x){
                high=mid-1;
            }
            else if(arr[mid]<x){
                low=mid+1;
            }
        }
        v[1]=ans_last;
        
        
        return v;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends