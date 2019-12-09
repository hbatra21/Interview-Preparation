void dfs(vector<string> &A, int i, int j, vector<vector<bool>> &vis , vector<vector<int>> &check )
{
    if(i < 0 || i >= A.size()) return;
    if(j < 0 || j >= A[0].size()) return;
    if(check[i][j] == 0 || vis[i][j] == true) return;
    vis[i][j] = true;
    dfs(A, i+1, j, vis, check );
    dfs(A, i-1, j, vis, check );
    dfs(A, i, j+1, vis, check );
    dfs(A, i, j-1, vis, check );
    
}
int Solution::black(vector<string> &A) {
    if(A.size() == 0) return 0;
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> check(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 'X'){
                check[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(check[i][j] == 1 && !vis[i][j]){
                dfs(A, i, j, vis, check );
                ans++;
            }
        }
    }
    return ans;
}
