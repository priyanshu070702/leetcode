class Solution {
public:

    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int shortestPathAllKeys(vector<string>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> que;
        vector<vector<unsigned long>> mapKey(m, vector<unsigned long>(n, 0));
        int target = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ('a' <= grid[i][j] && grid[i][j] <= 'f') {
                    target |= 1 << (grid[i][j] - 'a');
                    continue;
                }

                if (grid[i][j] == '@') {
                    que.emplace(pair<int, int>(i, j), 0);
                    mapKey[i][j] = 1;
                }
            }
        }


        int step = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int s = 0; s < size; s++) {
                int i = que.front().first.first;
                int j = que.front().first.second;
                int key = que.front().second;
                que.pop();
                
                if ('a' <= grid[i][j] && grid[i][j] <= 'f') {
                    key |= 1 << (grid[i][j] - 'a');
                    if (key == target)
                        return step;

                    mapKey[i][j] |= 1l << key;
                }

                for (int d = 0; d < 4; d++) {
                    int newi = i + dir[d][0];
                    int newj = j + dir[d][1];
                    
                    if (!(0 <= newi && newi < m && 0 <= newj && newj < n))
                        continue;
                        
                    int val = grid[newi][newj];
                    if (val == '#')
                        continue;
                        
                    if ('A' <= val && val <= 'F' && (key & (1 << (val - 'A'))) == 0)
                        continue;
                        
                    if (mapKey[newi][newj] & (1l << key))
                        continue;
                        
                     mapKey[newi][newj] |= 1l << key;
                     que.emplace(pair<int, int>(newi, newj), key);
                }
            }
            step++;
        }
        return -1;
    }
};