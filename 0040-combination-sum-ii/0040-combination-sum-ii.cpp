class Solution {
public:
    void solveRec(vector<int>&candidates, int target, set<vector<int>>&s, vector<vector<int>>&ans, int idx, int n, vector<int>&st){
        if(target==0){
            s.insert(st);
            return;
        }
        if(target<0 || idx>=n)return;
        
        if(candidates[idx]<=target){
            st.push_back(candidates[idx]);
            solveRec(candidates, target-candidates[idx], s,ans,idx+1,n,st);
            st.pop_back();
        }
        while(idx+1<candidates.size() && candidates[idx] == candidates[idx+1]){
            idx++;
        }
        solveRec(candidates,target,s,ans,idx+1,n,st);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int>st;
        set<vector<int>>s;
        vector<vector<int>>ans;
        solveRec(candidates, target, s, ans, 0,n,st);
        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
};