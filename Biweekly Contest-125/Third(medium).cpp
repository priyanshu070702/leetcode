class Solution {
private:
    int dfs(int node, int par, int dis, vector<pair<int, int>> adj[], int ss){
        int cnt = (dis % ss) ? 0 : 1;
        for(auto it:adj[node]){
            if(it.first!=par){
                cnt += dfs(it.first, node, dis+it.second, adj, ss);
            }
        }
        return cnt;
    }
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int ss) {
        int n = edges.size()+1;
        vector<pair<int, int>> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> ans;
        for(int u=0; u<n; u++){
            int nodeCnt = 0, res = 0;
            for(auto it:adj[u]){
                int cnt = dfs(it.first, u, it.second, adj, ss);
                res += cnt * nodeCnt;
                nodeCnt += cnt;
            }
            ans.push_back(res);
        }
        return ans;
    }
};