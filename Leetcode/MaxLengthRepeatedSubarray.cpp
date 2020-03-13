class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.size() == 0 ||B.size() == 0)
            return 0;
        int m = A.size();
        int n = B.size();
        int maxi = 0;
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0)); 
        for(int i = 0;i <= m;i++){
            for(int j = 0;j <= n;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    if(A[i - 1] == B[j - 1]){
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        maxi = max(maxi, dp[i][j]);
                    }
                }
            }
        }
        return maxi;
    }
};
