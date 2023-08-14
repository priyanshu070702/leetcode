//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // vector<int>ans;
        // for(auto it:mp){
        //     if(it.second==1)ans.push_back(it.first);
        // }
        // return ans;
        
        sort(nums.begin(),nums.end());
        nums.push_back(-1);
        vector<int>ans;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i]==nums[i+1]){
                i=i+2;
            }
            else{
                ans.push_back(nums[i]);
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends