class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //linear search
        // nums.insert(nums.begin(),INT_MIN);
        // nums.push_back(INT_MIN);
        // int n=nums.size();
        // for(int i=1;i<n-1;i++){
        //     if(nums[i]>nums[i-1] && nums[i]>nums[i+1])return i-1;
        // }
        // return 0;
        
        //binary search
        int s=0;
        int e=nums.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]<nums[mid+1]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return e;
    }
};