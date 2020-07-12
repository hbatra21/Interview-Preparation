int dfs(vector<vector<int>> &g, int n, int i, vector<bool> &vis, int parent){
    vis[i] = true;
    for(auto it : g[i]){
        if(!vis[it]){
            if(dfs(g, n, it, vis, i))
                return true;}
        else if(it != parent)
            return true;
    }
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>>g(A);
    for(auto i : B){
        g[i[0]-1].push_back(i[1]-1);
        g[i[1]-1].push_back(i[0]-1);
    }
    vector<bool>vis(A, false);
    for(int i = 0; i < A; i++){
        if(!vis[i])
            if(dfs(g, A, i, vis, -1))
                return 1;
    }
    return 0;
    
}
