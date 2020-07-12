int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    int m, n;
    vector<vector<bool>>visited;
    vector<vector<bool>>isX;
void DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<vector<bool>>& isX,
        int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || board[x][y] == 'X')
            return;
        visited[x][y] = true;
        isX[x][y] = false;
        DFS(board, visited, isX, x+1, y);
        DFS(board, visited, isX, x-1, y);
        DFS(board, visited, isX, x, y+1);
        DFS(board, visited, isX, x, y-1);
    }
void Solution::solve(vector<vector<char> > &board) {
    if (board.size() == 0)
            return;
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        isX = vector<vector<bool>>(m, vector<bool>(n, true));
        for(int i=0;i<m;i++)
            for (int j = 0; j < n; j++) {
                if((i==0||j==0||i==m-1||j==n-1)&&board[i][j]=='O')
                    DFS(board, visited, isX, i, j);
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (isX[i][j])
                    board[i][j] = 'X';
                else
                    board[i][j] = 'O';
            }
    }
