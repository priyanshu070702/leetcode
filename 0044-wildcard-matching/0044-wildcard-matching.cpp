class Solution {
public:
    bool func(string &str, string &pattern, int i, int j, vector<vector<int>>&dp){
        //base case
        if(i<0 && j<0)return true;
        if(i>=0 && j<0)return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(pattern[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //matching str and pattern 
        if(str[i]==pattern[j] || pattern[j]=='?'){
            return dp[i][j]=func(str,pattern,i-1,j-1,dp);
        }
        else if(pattern[j]=='*'){
            return dp[i][j]=(func(str,pattern,i-1,j,dp) || func(str,pattern,i,j-1,dp));
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int ls=s.length()-1;
        int lp=p.length()-1;
        vector<vector<int>>dp(ls+1,vector<int>(lp+1,-1)); 
        return func(s,p,ls,lp,dp);
    }
};