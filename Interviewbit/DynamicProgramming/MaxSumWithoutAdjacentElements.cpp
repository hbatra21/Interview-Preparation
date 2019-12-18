int Solution::adjacent(vector<vector<int> > &A) {
    int dp[A[0].size()+1];
    
    dp[0]=0;
    dp[1]=max(A[0][0],A[1][0]);
    dp[2]=max(A[0][1],A[1][1]);
    for(int i=3;i<=A[0].size();i++)
    {
        dp[i]=max(A[0][i-1],A[1][i-1])+max(dp[i-2],dp[i-3]);
    }
    return max(dp[A[0].size()],dp[A[0].size()-1]);
}
