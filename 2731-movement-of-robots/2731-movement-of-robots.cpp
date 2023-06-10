class Solution {
public:
     int mod=(1e9 + 7);
    int sumDistance(vector<int>& nums, string s, int d) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                nums[i] -= d;
            } else if (s[i] == 'R') {
                nums[i] += d;
            }
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += 1LL*nums[i] * i - sum;
            ans%=mod;
            sum += nums[i];
            sum%=mod;
        }
        return ans % (int)(1e9 + 7);
    }

};