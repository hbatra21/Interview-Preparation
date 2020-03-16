class Solution {
public:
    int DFS(vector<vector<int>>& matrix, int x, int y, int val, vector<vector<int>>& hash)
    {
        if(x < 0 || x >= matrix.size() || y <0 || y >= matrix[0].size())
            return 0;
        if(matrix[x][y] > val){
            if(hash[x][y] != 0) 
                return hash[x][y]; 
            int a = DFS(matrix, x, y+1,matrix[x][y], hash) + 1;
            int b = DFS(matrix, x, y-1,matrix[x][y], hash) + 1;
            int c = DFS(matrix, x+1, y,matrix[x][y], hash) + 1;
            int d = DFS(matrix, x-1, y,matrix[x][y], hash) + 1;
            hash[x][y] = max(a, max(b,max(c, d)));
            return hash[x][y];
        }
        return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        int Max = 0, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> hash(n, vector<int>(m, 0));
        for(int i = 0; i< n; i++)
            for(int j = 0; j < m; j++)
                Max = max(DFS(matrix, i, j, INT_MIN, hash), Max);
        return Max;
    }
};
