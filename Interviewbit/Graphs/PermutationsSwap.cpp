void dfs(vector<vector<int>>&graph, vector<int>&vis, vector<int>&a,int curr) {
    a.push_back(curr);
    vis[curr]=1;
    for(auto it : graph[curr]){
        if(vis[it]==0){
            dfs(graph, vis, a, it);
        }
    }
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size();
    vector<vector<int>>graph(n);
    vector<int>vis(n,0);
    for(int i=0;i<C.size();i++) {
        graph[C[i][0]-1].push_back(C[i][1]-1);
        graph[C[i][1]-1].push_back(C[i][0]-1);
    }
    for(int i=0;i<n;i++) {
        if(vis[i]==0) {
            vector<int>a, b, c;
            a.clear(); b.clear(); c.clear();
            dfs(graph,vis,a,i);
            for(int j=0;j<a.size();j++) {
                b.push_back(A[a[j]]-1);
                c.push_back(B[a[j]]-1);
            }
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        for(int j=0;j<b.size();j++)
            if(b[j] != c[j])
                return 0;
        }
    }
    return 1;
}
