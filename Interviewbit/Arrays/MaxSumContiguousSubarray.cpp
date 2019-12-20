int Solution::maxSubArray(const vector<int> &A) {
    int i;
    int ans = A[0],sum=A[0];
    for(i = 1; i < A.size(); i++) {
      sum = max(sum + A[i], A[i]);
        if(ans <sum)
            ans = sum;
    }
    return ans;
}

