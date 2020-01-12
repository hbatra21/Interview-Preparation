// BRUTE FORCE O(n^4)

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        
        for(int i=0;i<mat.size();++i) {
            for(int j=0;j<mat[0].size();++j) {
                for(int r=i-K;r<=i+K;++r) {
                    for(int c=j-K;c<=j+K;++c) {
                        if (r>=0&&r<mat.size()&&c>=0&&c<mat[0].size())
                          ans[i][j]+=mat[r][c];
                    }
                }
            }
        }
        return ans;
    }
};

// DP SOLUTION

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        std::vector<std::vector<int>>  ret;
        int m = mat.size();
        int n = mat[0].size();
        std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,0));
        for(int i = 1; i <= mat.size(); i++)
        {
            for(int j = 1; j <= mat[0].size(); j++)
            {
                dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        for(int i = 0; i < mat.size(); i++)
        {
            std::vector<int> temp;
            for(int j = 0; j < mat[0].size(); j++)
            {
                int rBegin = std::max(0,i - K);
                int rEnd = std::min(m-1,i + K);
                int cBegin = std::max(0,j - K);
                int cEnd = std::min(n - 1, j+K);
                int value = dp[rEnd+1][cEnd+1] - dp[rEnd+1][cBegin] - dp[rBegin][cEnd+1] + dp[rBegin][cBegin];
                temp.push_back(value);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
