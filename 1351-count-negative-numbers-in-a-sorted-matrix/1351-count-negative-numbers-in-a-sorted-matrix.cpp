class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        //brute force solution (n*m)
        // int n=grid.size();
        // int m=grid[0].size();
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]<0)cnt++;
        //     }
        // }
        // return cnt;

        //optimized solution O(n+m)
        int i=0;
        int j=grid[0].size()-1;
        int count=0;
        while(i<grid.size() && j>=0){
            if(grid[i][j]<0){
                count+=grid.size()-i;
                j--;
            }
            else{
                i++;
            }
        }
        return count;
    }
};