class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>res;
        string s="";
        for(int i=0;i<words.size();i++){
            string st=words[i];
            for(int j=0;j<st.length();j++){
                if(st[j]==separator){
                    if(s.length()>0){
                        res.push_back(s);
                        s="";
                    }
                    else continue;
                }
                else{
                    s+=st[j];
                }
            }
            res.push_back(s);
            s="";
        }
        vector<string>finale;
        for(int i=0;i<res.size();i++){
            if(res[i]!="")finale.push_back(res[i]);
        }
        return finale;
    }
};