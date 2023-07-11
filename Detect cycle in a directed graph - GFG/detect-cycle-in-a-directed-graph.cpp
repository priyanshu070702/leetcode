//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool cycle(int node,vector<bool>&vis,vector<bool>&dfsVis,vector<int>adj[]){
        vis[node]=true;
        dfsVis[node]=true;
        for(auto it:adj[node]){
            if(vis[it]==false){
                cycle(it,vis,dfsVis,adj);
                if(cycle(it,vis,dfsVis,adj)==true)return true;
            }
            else if(vis[it]==true && dfsVis[it]==true)return true;
        }
        dfsVis[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        vector<bool>dfsVis(V,false);
        for(int i=0;i<V;i++){
            if(cycle(i,vis,dfsVis,adj)==true){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends