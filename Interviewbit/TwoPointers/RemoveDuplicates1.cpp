int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    if(n == 0 || n == 1)
        return n;
    int k = 0;
    for(int i = 1; i < n; i++){
        if(A[k] != A[i]){
            A[k+1] = A[i];
            k++;
        }
    }
    return k+1;
    
}
