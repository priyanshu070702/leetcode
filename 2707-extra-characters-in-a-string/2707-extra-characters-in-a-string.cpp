class Solution {
public:
    int n;
    unordered_set<string> st;

    int solve(int index, string &s, vector<int>& dp) {
        if(index >= n) {
            return 0;
        }

        if(dp[index] != -1) {
            return dp[index];
        }

        string currStr = "";
        int minExtra = n;      

        for(int i=index; i<n; i++) {
            currStr.push_back(s[i]);
            int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0;
            int remainingExtra = solve(i+1, s, dp);
            int totalExtra = currExtra + remainingExtra;

            minExtra = min(minExtra, totalExtra);
        }

        return dp[index] = minExtra;
    }

    int minExtraChar(string s, vector<string>& dictionary) {

        n = s.length();
        vector<int> dp(n+1, -1);

        for(auto &word: dictionary) {
            st.insert(word);
        }

        return solve(0, s, dp);
    }
};