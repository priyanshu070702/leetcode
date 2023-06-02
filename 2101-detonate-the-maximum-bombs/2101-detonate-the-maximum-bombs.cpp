class Solution {
public:
    //general dfs algorithm to find all the connected bombs (you can use bfs as well)
    void dfs(int node, vector<int> &visited, vector<int> adj[], int &cnt){
        visited[node] = 1;
        cnt++;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, visited, adj, cnt);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];

        //make a directed graph of the distance of bombs with one another
        //if the radius of a bomb is greater than the distance with another bomb -> it means there is a directed edge between them
        for(int i=0; i<n; i++){
            long long int x0, y0, r0;
            x0 = bombs[i][0];
            y0 = bombs[i][1];
            r0 = bombs[i][2];

            for(int j=0; j<n; j++){
                //if i and j are equal it means both bombs are same so there is no need to check
                if(i != j){
                    long long int x, y;
                    x = abs(x0 - bombs[j][0]);
                    y = abs(y0 - bombs[j][1]);

                    if(x*x + y*y <= r0*r0){
                        adj[i].push_back(j);
                    }
                }
            }
        }

        //call dfs for every node to see how many bombs are connected with that single bomb
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int cnt = 0;
            vector<int> visited(n, 0);
            dfs(i, visited, adj, cnt);

            ans = max(ans, cnt);
        }

        //return the bomb with maximum number of connected bombs
        return ans;
    }
};