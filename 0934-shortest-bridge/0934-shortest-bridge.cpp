class Solution {
public:
    const int dx[4]={-1,1,0,0};
      const int dy[4]={0,0,-1,1};
    //boundary checks
    bool  isValid(int i,int j,int r,int c){
          return (i<r && j<c && i>=0 && j>=0);
    }
 
    void changeIslandType(int i,int j,int r,int c,vector<vector<int>>& grid){

        if(i>=r || j>=c || i<0 || j<0 || grid[i][j]==0 || grid[i][j]==2)return;
        grid[i][j]=2;
        for(int x=0;x<4;++x){
            int nr=i+dx[x];
            int nc=j+dy[x];
            changeIslandType(nr,nc,r,c, grid);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
 
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;
 
        int change=0;
        bool check=false;
        //change the islands
        for(int i=0;i<r;++i){

            for(int j=0;j<c;++j){

               if(grid[i][j]){
                   changeIslandType(i,j,r,c,grid);
                   check=true;
                   break;
               }
            }

            if(check)
            break;
        }
 
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
               if(grid[i][j]==2){
                q.push({i,j});       
               }
            }
        }
 
 
        while(!q.empty()){
            change++;
         int sz=q.size();

            while(sz--){
               auto node=q.front();
               q.pop();
                //4 directions
               for(int x=0;x<4;++x){
                   int nr=node.first+dx[x];
                   int nc=node.second+dy[x];
 
                   if(isValid(nr,nc,r,c) ){
                       
                         if( grid[nr][nc]==0){
                             grid[nr][nc]=2;
                             q.push({nr,nc});
                         }

                         if(grid[nr][nc]==1)
                         return change-1; 
                   }  
               }     
            }
        }
 
       return 0; 
 
    }
};