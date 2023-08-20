//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    //O(n)
	   // int cnt=0;
	   // for(int i=0;i<n;i++){
	   //     if(x==arr[i])cnt++;
	   // }
	   // return cnt;
	   
	   //O(logn)
	   int low=0,high=n-1;
	   int first_occurence=-1;
	   while(low<=high){
	       int mid=low+(high-low)/2;
	       if(arr[mid]==x){
	           first_occurence=mid;
	           high=mid-1;
	       }
	       else if(arr[mid]<x){
	           low=mid+1;
	       }
	       else{
	           high=mid-1;
	       }
	   }
	   
	   if(first_occurence==-1)return 0;
	   
	   low=0,high=n-1;
	   int last_occurence=0;
	   while(low<=high){
	       int mid=low+(high-low)/2;
	       if(arr[mid]==x){
	           last_occurence=mid;
	           low=mid+1;
	       }
	       else if(arr[mid]<x){
	           low=mid+1;
	       }
	       else{
	           high=mid-1;
	       }
	   }
	   int number_of_occurences=last_occurence-first_occurence+1;
	   return number_of_occurences;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends