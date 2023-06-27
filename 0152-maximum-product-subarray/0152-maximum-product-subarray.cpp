class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int suff=1;
        int pre=1;
        int ans=INT_MIN;
        int i=0,j=n-1;
        while(i<n && j>=0){
            if(pre==0)pre=1;
            if(suff==0)suff=1;
            
            pre=pre*nums[i++];
            suff=suff*nums[j--];
            
            ans=max(ans,max(pre,suff));
        }
        return ans;
    }
};