class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        unordered_map<char,int>freq;
        unordered_map<char,bool>vis;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(vis[s[i]]==true){
                freq[s[i]]--;
                continue;
            }
            while(!st.empty() && st.top()>s[i] && freq[st.top()]>0){
                vis[st.top()]=false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]]=true;
            freq[s[i]]--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};