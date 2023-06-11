class Solution {
public:
    string smallestString(string s) {
        int n=s.length();
        if(s.length()==1){
            if(s[0]=='a')s[0]='z';
            else{
                s[0]=s[0]-1;
            }
            return s;
        }
        int i=0;
        while(i<n){
            if(s[i]=='a'){
                i++;
            }
            else break;
        }
        if(i==n){
             s[n-1]='z';
            return s;
        }
        for(;i<n;i++){
            if(s[i]!='a'){
                s[i]=s[i]-1;
            }
            else{
                break;
            }
        }
        return s;
    }
};