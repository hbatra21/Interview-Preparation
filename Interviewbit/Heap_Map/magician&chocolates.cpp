int choco(int A, priority_queue<int> q){
    int n = q.size();
    long long int mod = pow(10, 9) + 7;
    int sum = 0;
    for(int i = 0; i < A; i++){
        int val = q.top();
        sum = (sum + (val) % mod) % mod;
        q.pop();
        q.push(val/2);
    }
    return sum;
}
int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> q;
    if(B.size() == 0) return 0;
    for(int i = 0; i < B.size(); i++)
        q.push(B[i]);
    int ans = choco(A, q);
    return ans;
}
