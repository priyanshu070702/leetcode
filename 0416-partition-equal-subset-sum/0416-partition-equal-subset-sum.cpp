class Solution {
public:
    bool sumRec(vector<int>&nums, int n,int target, int index){
        if(index>=n)return 0;
        if(target==0)return 1;
        bool include=false;
        if(nums[index]<=target){
            include=sumRec(nums,n,target-nums[index],index+1);
        }
        bool exclude=sumRec(nums,n,target,index+1);
        return include || exclude;
    }

    bool sumMemo(vector<int>&nums, int n,int target, int index, vector<vector<int>>&dp){
        if(index>=n)return 0;
        if(target==0)return 1;
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        bool include=false;
        if(nums[index]<=target){
            include=sumMemo(nums,n,target-nums[index],index+1,dp);
        }
        bool exclude=sumMemo(nums,n,target,index+1,dp);
        return dp[index][target]= include || exclude;
    }

    bool sumTab(vector<int>&nums, int n,int target){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int i=n-1;i>=0;i++){
            for(int j=1;j<=target;j++){
                bool include=false;
                if(nums[i]<=target){
                   include=dp[i+1][j-nums[i]];
                }
                  bool exclude=dp[i+1][j];

                   dp[i][j]=include||exclude;
            }
        }
        return dp[0][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        int target=sum/2;
        //return sumRec(nums,n,target,0);
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return sumMemo(nums,n,target,0,dp);
    }
};