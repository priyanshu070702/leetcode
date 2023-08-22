class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int n = columnNumber ;
        while(n)
        {
            n--;
            ans += char('A'+n%26);
            n = n/26;
        }     
        reverse(ans.begin(),ans.end());
        return ans;
    }
};