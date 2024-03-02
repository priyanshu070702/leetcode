class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k)cnt++;
        }
        return cnt;
    }
};