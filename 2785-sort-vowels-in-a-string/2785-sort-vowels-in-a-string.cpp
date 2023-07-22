class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')return  true;
        return false;
    }
    string sortVowels(string s) {
        vector<char>v;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])==true)v.push_back(s[i]);
        }
        sort(v.begin(),v.end());
        int p=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])==true){
                s[i]=v[p];
                p++;
            }
        }
        return s;
    }
};