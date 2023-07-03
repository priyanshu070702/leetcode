class Solution {
public:
    void generate(int open, int close, string &s, vector<string>&ans){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        //for open bracket
        if(open>0){
            s.push_back('(');
            generate(open-1,close,s,ans);
            s.pop_back();
        }
        //for close bracket
        if(close>0 && open<close){
           s.push_back(')');
            generate(open,close-1,s,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>ans;
        generate(n,n,s,ans);
        return ans;
    }
};