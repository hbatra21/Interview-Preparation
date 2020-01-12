class Solution {
public:
    void dfs(vector<vector<int>> &graph, int u, vector<bool> &visited) {
        visited[u] = true;
        for (auto v : graph[u]) {
            if (!visited[v])
                dfs(graph, v, visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) 
            return -1;
        vector<vector<int>> graph(n);  
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(graph, i, visited);
                ++cnt;
            }
        }
        return cnt - 1;    
    }
};
