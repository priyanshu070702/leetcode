class Solution {
public:
    unordered_map<int, int> mp;
    bool check(string &s, int ref, int i){
        string str = s.substr(i);
        int t = stoi(str);
        if(ref > t || ref < 0 || s.size() == i) return false;
        if(t == ref) return true;
        for(int j = 1; i+j < s.size(); ++j){
            str = s.substr(i, j);
            if(check(s, ref - stoi(str), i+j)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            string sqr = to_string(i*i);           
            if(mp.find(i*i) == mp.end() ) mp[i*i] = check(sqr, i, 0); 
            ans += i*i * mp[i*i];
        }
        return ans;
    }
};