class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
         int l=0;
        if(s.length()==1)return 1;
        for(int i=0;i<s.length()-1;i++){
            int cnt=0;
            int len=1;
            for(int j=i;j<s.length()-1;j++){
                if(s[j]==s[j+1]){
                    cnt++;
                    if(cnt>1)break;
                    len++;
                }
                else{
                    len++;
                }
            }
            l=max(l,len);
        }
        return l;
    }
};