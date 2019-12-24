int bs(vector<int > A, int st, int en, int B){
    while(st <= en){
        int mid = (st + en)/2;
        if(A[mid] == B) return 1;
        else if(A[mid] < B) st = mid + 1;
        else en = mid-1;
    }
    return 0;
}
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int m = A.size();
    int n = A[0].size();
    for(int i = 0; i < m; i++){
        if((A[i][0] <= B) && (A[i][n-1] >= B)){
            if(bs(A[i], 0, n - 1, B)) return 1;
            else return 0;
        }
    }
    return 0;
}
