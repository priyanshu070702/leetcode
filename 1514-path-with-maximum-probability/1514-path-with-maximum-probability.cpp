class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> graph;
        
        vector<vector<pair<int,float>>>g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
            g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        vector<double>v(n,0);
        v[start]=1.0;
        
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            if(curr.second==end){
                return curr.first;
            }    
            for(auto adj:g[curr.second]){
                if(v[adj.first]<curr.first*adj.second){
                    v[adj.first]=curr.first*adj.second;
                    pq.push({v[adj.first],adj.first});
                }
            }
        }
        return 0;
    }
};