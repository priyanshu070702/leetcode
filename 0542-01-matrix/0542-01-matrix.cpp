class Solution {
public:
    bool isSafe(int i, int j, int n, int m){
        if(i>=0 && i< n && j>=0 && j<m)return true;
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int n_row=it.first.first;
            int r_col=it.first.second;
            int cnt=it.second;
            dist[n_row][r_col]=cnt;
            for(int i=0;i<4;i++){
                int r=n_row+dx[i];
                int c=r_col+dy[i];
                if(isSafe(r,c,n,m) && vis[r][c]==0){
                    q.push({{r,c},cnt+1});
                    vis[r][c]=1;
                }
            }
        }
        return dist;
    }
};