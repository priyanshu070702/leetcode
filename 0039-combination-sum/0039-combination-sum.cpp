class Solution {
public:
    vector<vector<int>>ans;
    void solveRec(vector<int>&candidates, int target, vector<int>&st, int idx){
        if(idx==candidates.size())return;
        if(target<0)return;
        if(target==0){
            ans.push_back(st);
            return;
        }
        if(candidates[idx]<=target){
            st.push_back(candidates[idx]);
            solveRec(candidates, target-candidates[idx], st, idx);
            st.pop_back();
        }
        solveRec(candidates, target, st, idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>st;
        solveRec(candidates,target,st,0);
        return ans;
    }
};