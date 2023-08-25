class Solution {
public:
    bool solve(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &dp)
    {
        if(i == s1.length() && j == s2.length() && k == s3.length() )
            return true;
        
        if(i < s1.length() && j < s2.length() && dp[i][j] != -1)
            return dp[i][j];
        
        if(j <= s2.length() - 1 && s2[j] == s3[k] && i <= s1.length() - 1 && s1[i] == s3[k])
            return dp[i][j] = solve(s1, s2, s3, i + 1, j, k + 1, dp) || solve(s1, s2, s3, i, j + 1, k + 1, dp);

        else if(i <= s1.length() - 1 && s1[i] == s3[k])
            return dp[i][j] = solve(s1, s2, s3, i + 1, j, k + 1, dp);

        else if(j <= s2.length() - 1 && s2[j] == s3[k])
            return dp[i][j] = solve(s1, s2, s3, i, j + 1, k + 1, dp);
        
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() < s3.length())
            return false;
        vector<vector<int>>dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return solve(s1, s2, s3, 0, 0, 0, dp);
    }
};