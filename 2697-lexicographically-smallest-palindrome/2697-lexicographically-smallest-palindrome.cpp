class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while(i<j){
            if(s[i] != s[j]){
                s[i] = s[j] = min(s[i],s[j]);
            }
            i++;j--;
        }
        return s;
    }
};