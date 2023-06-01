class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        int dx[8]={1,-1,0,0,1,1,-1,-1};
        int dy[8]={0,0,1,-1,1,-1,1,-1};
        queue<pair<int,int>>q;
        grid[0][0]=1;
        q.push({0,0});
        int res=0;
        while(!q.empty()){
            int k=q.size();
            res++;
            while(k--){
                auto p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                if(x==n-1 && y==n-1)return res;
                for(int i=0;i<8;i++){
                    int xx=x+dx[i];
                    int yy=y+dy[i];
                    if(xx>=0 && xx<n && yy>=0 && yy<n && grid[xx][yy]==0){
                        grid[xx][yy]=1;
                        q.push({xx,yy});
                    }
                }
            }
        }
        return -1;
    }
};