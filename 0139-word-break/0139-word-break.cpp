class Solution {
private:
    bool solve(string& s,vector<string>& words,int i,vector<int>& dp)
    {
        int n=s.size();
        //Base case
        if(i==n)
            return true;
        //Check if already calculated
        if(dp[i]!=-1)
            return dp[i];
        
        bool ans=false;
        //Try to break for every index
        for(int ind=0;ind<=n-i;ind++)
        {
            //If we find the word in the given vector then check for the next one
            if(find(words.begin(),words.end(),s.substr(i,ind))!=words.end())
            {
                ans|=solve(s,words,i+ind,dp);
            }
        }
        //Memoize
        return dp[i]=ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return solve(s,wordDict,0,dp);
        
    }
};