class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        string s=*min_element(strs.begin(),strs.end());
        
        if(strs.size()==0){
            return ans;
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<strs.size();j++){
                if(s[i]!=strs[j][i]){
                    return ans;
                }
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};