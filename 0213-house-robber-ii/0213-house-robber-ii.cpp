class Solution {
public:
    int robRec(vector<int>&nums, int index, int n){
        if(index>=n){
            return 0;
        }
        int include=nums[index]+robRec(nums,index+2,n);
        int exclude=robRec(nums,index+1,n);
        
        return max(include, exclude);
    }
    int robMemo(vector<int>&nums, int index, int n, vector<int>&dp){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int include=nums[index]+robMemo(nums,index+2,n,dp);
        int exclude=robMemo(nums,index+1,n,dp);
        
        return dp[index] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // int a1=robRec(nums,0,n-1);
        // int a2=robRec(nums,1,n);
        // return max(a1,a2);
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int a1=robMemo(nums,0,n-1,dp1);
        int a2=robMemo(nums,1,n,dp2);
        return max(a1,a2);
    }
};