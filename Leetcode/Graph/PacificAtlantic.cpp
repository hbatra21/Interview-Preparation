class Solution {
public:
     vector<pair<int, int>>dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>>res;
        if(matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                bool reachP = false, reachA = false;
                DFS( matrix, i, j, m, n, reachP, reachA);
                if(reachP && reachA) res.push_back({i, j});
            }
        return res;
    }
    
    void DFS( vector<vector<int>>& matrix, int r, int c, int m, int n, bool& reachP, bool& reachA){
        if(matrix[r][c] == -1 || reachP && reachA) return;
        int tmp = matrix[r][c];
        matrix[r][c] = -1;
        for(int i = 0; i < 4; i++){
            int R = r + dir[i].first, C = c + dir[i].second;
            if(R < 0 || C < 0) reachP = true;
            else if(R == m || C == n) reachA = true;
            else if(matrix[R][C] <= tmp) DFS( matrix, R, C, m, n, reachP, reachA);
        }
        matrix[r][c] = tmp;
    }

};
