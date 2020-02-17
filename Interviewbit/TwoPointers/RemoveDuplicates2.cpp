int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    if (n <= 2)
        return n;
    int rear = 1;
    for(int i = 2; i < n; i++){
        if(!(A[i] == A[rear] && A[i] == A[rear -1])){
            A[++rear] = A[i];
            }
        }                    
        return rear+1;
    }
