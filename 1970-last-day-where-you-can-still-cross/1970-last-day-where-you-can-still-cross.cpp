class Solution {
public:
    bool isPossible(int m, int n, int mid, vector<vector<int>>&cells){
        vector<vector<int>>grid(m+1,vector<int>(n+1,0));
        vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<mid;i++){
            grid[cells[i][0]][cells[i][1]]=1;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<=n;i++){
            if(grid[1][i]==0){
                q.push({1,i});
                grid[1][i]=1;
            }
        }
        while(!q.empty()){
            auto fro=q.front();
            q.pop();
            int r=fro.first;
            int c=fro.second;
            for(auto d:dir){
                int nr=r+d.first;
                int nc=c+d.second;
                if(nr>0 && nr<=m && nc>0 &&nc<=n && grid[nr][nc]==0){
                    grid[nr][nc]=1;
                    if(nr==m){
                        return 1;
                    }
                    q.push({nr,nc});
                }
            }
        }
        return 0;
        
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left=0;
        int right=row*col;
        int days=0;
        while(left<right-1){
            int mid=left+((right-left)/2);
            if(isPossible(row,col,mid,cells)){
                left=mid;
                days=mid;
            }
            else{
                right=mid;
            }
        }
        return days;
    }
};