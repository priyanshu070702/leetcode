class Solution {
public:
    static bool comp(pair<int,int>&a, pair<int,int>&b){
        if(a.first<b.first){
            return true;
        }
        else if(a.first == b.first){
            if(a.second<b.second){
                return true;
            }
            return false;
        }
        return false;
    }
    int solveRec(vector<pair<int,int>>p, int idx, int prev, int sz, vector<vector<int>>&dp){
        if(idx==sz)return 0; //base condition
        
        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
        
        int pick=0;
        if(prev==-1 || p[idx].first>p[prev].second){
            pick=1+solveRec(p,idx+1,idx,sz,dp);
        }
        int not_pick=0+solveRec(p,idx+1,prev,sz,dp);
        
        return dp[idx][prev+1]=max(pick,not_pick);
        
    }
    int solveTab(vector<pair<int,int>>p){
        int sz=p.size();
        vector<vector<int>>dp(sz+1,vector<int>(sz+2,0));
        
        for(int idx=sz-1;idx>=0;idx--){
            for(int prev=idx-1;prev>=-1;prev--){
                int pick=0;
                
                if(prev==-1 || p[idx].first>p[prev].second){
                    pick=1+dp[idx+1][idx+1];
                }
                
                int not_pick=dp[idx+1][prev+1];

                dp[idx][prev+1]=max(pick,not_pick);
            }
        }
        return dp[0][0];
        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>>p;
        for(int i=0;i<pairs.size();i++){
            p.push_back({pairs[i][0],pairs[i][1]});
        }
        sort(p.begin(),p.end(),comp);
        
        // int sz=p.size();
        // vector<vector<int>>dp(sz+1,vector<int>(sz+2,-1));
        // return solveRec(p,0,-1,sz,dp);
        return solveTab(p);
    }
};