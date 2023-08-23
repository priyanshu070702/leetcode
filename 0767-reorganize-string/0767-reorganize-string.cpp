// class Solution {
// public:
//     string reorganizeString(string s) {
//         unordered_map<char,int>mp;
//         int n=s.length();
//         for(int i=0;i<n;i++){
//             mp[s[i]]++;
//         }
//         string ans="";
//         vector<char>st(n);
        
//         for(auto it:mp){
//             if(it.second>(n/2)+1)return ans;
//         }
        
//         int cnt=n;
//         int i=0;
//         while(cnt>0){
//             int mx=INT_MIN;
//             char comp;
//             for(auto it:mp){
//                 if(it.second>mx){
//                     comp=it.first;
//                     mx=it.second;
//                 }
//             }
//             while(mx--){
//                 st[i]=comp;
//                 i=(i+2)%n;
//                 cnt--;
//             }
//             auto it = mp.find(comp);
//             mp.erase(it);
//         }
//         for(int j=0;j<st.size();j++){
//             ans.push_back(st[i]);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }
        
        string ans = "";
        pair<int, char> prev = {-1, '#'};  // Initialize with a dummy character
        
        while (!pq.empty()) {
            pair<int, char> curr = pq.top();
            pq.pop();
            
            ans += curr.second;
            curr.first--;
            
            if (prev.first > 0) {
                pq.push(prev);
            }
            
            prev = curr;
        }
        
        if (ans.length() != s.length()) {
            return "";
        }
        
        return ans;
    }
};
