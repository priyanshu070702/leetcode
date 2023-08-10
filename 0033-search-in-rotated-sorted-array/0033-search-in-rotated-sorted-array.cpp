class Solution {
public:
    int find_pivot(vector<int>&nums){
        int s=0,e=nums.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[0]<=nums[mid])s=mid+1;
            else e=mid;
        }
        return e;
    }
    int binary_search(vector<int>&nums,int s, int e, int target){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)e=mid-1;
            else s=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //O(n)
        // for(int i=0;i<nums.size();i++){
        //     if(target==nums[i])return i;
        // }
        // return -1;
        
        //O(log n)
        
        //find pivot element
        int pivot=find_pivot(nums);
        int res;
        if(target>=nums[pivot] && target<=nums[nums.size()-1]){
            res=binary_search(nums, pivot, nums.size()-1, target);
        }
        else{
            res=binary_search(nums,0, pivot-1, target);
        }
        if(res==-1)return -1;
        return res;
    }
};