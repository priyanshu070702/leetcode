class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans = LONG_MAX;
    vector<int> checked(nums.size(), INT_MAX), cnum(nums.begin(), nums.end());
    for(auto n: nums) cnum.push_back(n);
    for(int i = 0; i < nums.size(); ++i){
        long long sum = 0;
        for(int j = 0; j < nums.size(); ++j){
            checked[j] = min(checked[j], cnum[i+j]);
            sum += checked[j];
        }
        sum += (long long)i*(long long)x;
        ans = min(ans, sum);
    }
    return ans;
    }
};