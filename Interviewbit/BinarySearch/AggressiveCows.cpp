bool isPossible(vector<int> &A, int dist, int B){
    int diff=0;
    int start = 0;
    int count=1;
    for(int i=1;i<A.size();i++){
        diff =  A[i]-A[start];
        if(diff>=dist){
            count++;
            if(count>=B) return true;
            start = i;
        }
    }
    
    return false;
}
int Solution::solve(vector<int> &A, int B) {
    
    sort(A.begin(), A.end());
    int maxm = A[A.size()-1];
    int minm = A[0];
    
    int start = 0, end = maxm-minm;
    int ans = INT_MIN;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(isPossible(A, mid, B)){
            ans = max(ans, mid);
            start = mid+1;
        }else{
            end = mid-1;
        }
        
    }
    
    return ans;
}
