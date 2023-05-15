class Solution {
public:
    vector<int> countBits(int n) {
        long long sum=0;
        vector<int>res;
        for(int i=0;i<=n;i++){
            res.push_back(__builtin_popcount(i));
        }
        return res;
    }
};
