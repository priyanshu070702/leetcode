class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;
        char cur = chars[0];
        int count = 1;
        string s;
        for (int i = 1; i <= chars.size(); i++) {
            if (i < chars.size() && chars[i] == cur) {
                count++;
            } else {
                s.push_back(cur);
                if (count > 1) {
                    string str = to_string(count);
                    for (char c : str) {
                        s.push_back(c);
                    }
                }
                cur = i < chars.size() ? chars[i] : 0;
                count = 1;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            chars[i] = s[i];
        }
        return s.size();
    }
};