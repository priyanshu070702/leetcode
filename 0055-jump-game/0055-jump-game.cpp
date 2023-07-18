class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxIdx=0;
        for(int i=0;i<nums.size();i++){
            if(i>mxIdx)return false;
            mxIdx=max(mxIdx,i+nums[i]);
        }
        return true;
    }
};