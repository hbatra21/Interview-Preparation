int Solution::maxp3(vector<int> &A) {
    int maxp = 0;
    int n = A.size();
    if(n<3)
        return 0;
    sort(A.begin(), A.end());
    maxp = max(A[0]*A[1]*A[n], A[n-1]*A[n-2]*A[n-3]);
    return maxp;
}
