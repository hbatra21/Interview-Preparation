class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size()==0)
            return;
        preSum = vector<vector<int>> (matrix.size() + 1,vector(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                preSum[i+1][j+1] = preSum[i+1][j] + preSum[i][j+1] - preSum[i][j] + matrix[i][j];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] + preSum[row1][col1]-preSum[row1][col2+1]-preSum[row2+1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
