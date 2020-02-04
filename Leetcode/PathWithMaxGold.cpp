class Solution {
public:
    vector<pair<int, int>> dirs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    
    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited) {
        int local = grid[x][y];   
        for (auto& dir : dirs) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (nx < 0||nx >= grid.size()||ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 0||visited[nx][ny])                continue;
            visited[nx][ny] = true;
            local = max(local, grid[x][y] + dfs(grid, nx, ny, visited));
            visited[nx][ny] = false;
        }
        
        return local;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        const int n = grid.size();
        if (n == 0) {
            return 0;
        }
        const int m = grid[0].size();
        if (m == 0) {
            return 0;
        }
        int global = 0;
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    visited[i][j] = true;
                    global = max(global, dfs(grid, i, j, visited));
                    visited[i][j] = false;
                }
            }
        }   
        return global;
    }
};
