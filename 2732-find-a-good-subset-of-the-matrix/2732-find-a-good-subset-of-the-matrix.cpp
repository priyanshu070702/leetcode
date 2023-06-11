class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_map<int, int>hsh;
        for(int i = 0; i < n; i++) {
            int val = 0;
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    val += (1 << j);
                }
            }

            if(val == 0) {
                return {i};
            }

            for(int j = 1; j < 32; j++) {
                if((val & j) == 0 and hsh.count(j)) {
                    return {hsh[j], i};
                }
            }
            hsh[val] = i;
        }      
        return {};
    }
};