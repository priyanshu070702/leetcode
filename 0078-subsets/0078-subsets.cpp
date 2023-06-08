class Solution {
public:
    void func(vector<int>nums, vector<int>store, int i, vector<vector<int>>&ans){
        if(i>=nums.size()){
            ans.push_back(store);
            return;
        }
        func(nums,store,i+1,ans);

        int ele=nums[i];
        store.push_back(ele);
        func(nums,store,i+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>store;
        int i=0;
        func(nums,store,i,ans);
        return ans;
    }
};