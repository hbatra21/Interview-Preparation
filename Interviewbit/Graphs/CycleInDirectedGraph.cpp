int dfs(vector<vector<int>>&g, int n, int i, vector<bool> &vis, vector<bool> &rec){
    vis[i] = true;
    rec[i] = true;
    for(auto it : g[i]){
        if(!vis[it]){
            if(dfs(g, n, it, vis, rec))
                return true;
        }
        if(rec[it] == true)
            return true;
    }
    rec[i] = false;
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>>g(A);
    for(auto i : B){
        g[i[0]-1].push_back(i[1]-1);
    }
    vector<bool>vis(A, false);
    vector<bool>rec(A, false);
    for(int i = 0; i < A; i++){
        if(!vis[i])
            if(dfs(g, A, i, vis, rec))
                return 1;
    }
    return 0;
}
