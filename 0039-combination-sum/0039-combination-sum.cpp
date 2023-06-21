class Solution {
public:
    void func_combi_sum(vector<vector<int>>&ans,int start,vector<int>&st, vector<int>& candidates, int target){
       if(target==0){
           ans.push_back(st);
           return;
       }
       if(target < 0){
            return;
        }
       for(int idx=start;idx<candidates.size();idx++){
           st.push_back(candidates[idx]);
           func_combi_sum(ans,idx,st,candidates,target-candidates[idx]);
           st.pop_back();
       }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){

        vector<vector<int>>ans;
        vector<int>store;
        func_combi_sum(ans,0,store,candidates,target);
        return ans;
    }
};