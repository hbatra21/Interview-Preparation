class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
		int m=mat.size();
		int n=mat[0].size();
		int res=0;
		vector<vector<int>> dp (m+1,vector<int>(n+1, 0));
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++){
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i-1][j-1];
			}

		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				for(int k=0;i+k<=m && j+k<=n;k++){
					if(dp[i+k][j+k]-dp[i-1][j+k]-dp[i+k][j-1]+dp[i-1][j-1]>threshold){
						break;
					}
					res=max(res,k+1);
				}
		return res;
    }
};
