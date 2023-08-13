class Solution {
public:
    bool is_pair(int a, int b){
        int mx_a=INT_MIN, mx_b=INT_MIN;
        while(a>0){
            int st=a%10;
            a=a/10;
            mx_a=max(mx_a,st);
        }
        while(b>0){
            int st=b%10;
            b=b/10;
            mx_b=max(mx_b,st);
        }
        if(mx_a==mx_b)return 1;
        return 0;
    }
    int maxSum(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(is_pair(nums[i],nums[j])){
                    ans=max(ans, nums[i]+nums[j]);
                }
            }
        }
        return ans;
    }
};