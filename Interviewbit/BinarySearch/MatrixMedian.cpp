int Solution::findMedian(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int min1 = INT_MAX;
    int max1 = INT_MIN;
    for (int i = 0; i < m; i++) 
    { 
        if (A[i][0] < min1) 
            min1 = A[i][0]; 
        if (A[i][n-1] > max1) 
            max1 = A[i][n-1]; 
    }
    int ans = (m * n + 1) / 2;
     while (min1 < max1) { 
        int mid = min1 + (max1 - min1) / 2; 
        int place = 0; 
        for (int i = 0; i < m; i++) 
            place += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin(); 
        if (place < ans) 
            min1 = mid + 1; 
        else
            max1 = mid; 
    } 
    return min1;
}
