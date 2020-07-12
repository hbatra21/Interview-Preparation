int dfs(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == 0) {
        return 0;
    }
    grid[i][j] = 0;
    return 1 + dfs(grid, i - 1, j+1) + dfs(grid, i - 1, j-1) +dfs(grid, i + 1, j-1) +
    dfs(grid, i + 1, j+1) + dfs(grid, i - 1, j) + dfs(grid, i, j-1) +
    dfs(grid, i , j+1) + dfs(grid, i + 1, j) ;
}
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int ans = 0;
    vector<vector<int>>vis(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 1){
                ans = max(ans, dfs(A, i, j));
            }
        }
    }
    return ans;
}
