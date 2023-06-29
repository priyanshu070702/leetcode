class Solution {
public:
    //recursion
    int recSatisfaction(vector<int>&sat, int time, int index){
        if(index==sat.size()){
            return 0;
        }
        //include
        int include=sat[index]*(time) + recSatisfaction(sat,time+1,index+1);
        
        //exclude
        int exclude=recSatisfaction(sat,time,index+1);
        
        return max(include,exclude);
    }
    //memoization
    int memoSatisfaction(vector<int>&sat, int time, int index, vector<vector<int>>&dp){
        if(index==sat.size()){
            return 0;
        }
        if(dp[time][index]!=-1){
            return dp[time][index];
        }
        //include
        int include=sat[index]*(time) + memoSatisfaction(sat,time+1,index+1,dp);
        
        //exclude
        int exclude=memoSatisfaction(sat,time,index+1,dp);
        
        dp[time][index] = max(include,exclude);
        return dp[time][index];
    }
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int n=sat.size();
        // return recSatisfaction(sat,1,0);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return memoSatisfaction(sat,1,0,dp);
    }
};