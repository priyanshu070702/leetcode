class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string,int>mp;
        int n=grid.size();
        for(int i=0;i<n;i++){
            string res="";
            for(int j=0;j<n;j++){
                res+=to_string(grid[i][j]);
                res+='#';
            }
            mp[res]++;
        }
        int ans=0;
        for(int j=0;j<n;j++){
            string res="";
            for(int i=0;i<n;i++){
                res+=to_string(grid[i][j]);
                res+='#';
            }
            ans+=mp[res];
        }
        return ans;
    }
};