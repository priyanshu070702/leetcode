class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,set<int>>adj;  //making adjacancy list 
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int sz=adj[i].size()+adj[j].size();
                if(adj[i].count(j)){
                    sz--;
                }
                ans=max(sz,ans);
            }
        }
        return ans;
    }
};