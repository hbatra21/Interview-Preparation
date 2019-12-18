int Solution::longestSubsequenceLength(const vector<int> &A) {
if(A.size() == 0){
        return 0;
    }
    int n = A.size(), sol = 1;
    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    vector<int> ans(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(A[i] > A[j]){
                inc[i] = max(inc[i], inc[j]+1);
                ans[i] = max(ans[i], inc[i]);
            }
            else if(A[i] < A[j]){
                dec[i] = max(dec[i], dec[j]+1);
                ans[i] = max(ans[i], max(dec[i], ans[j]+1));
            }
        }
        sol = max(sol, ans[i]);
    }
    return sol;
}
