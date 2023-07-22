class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(),INT_MIN);
        nums.push_back(INT_MIN);
        int n=nums.size();
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])return i-1;
        }
        return 0;
    }
};