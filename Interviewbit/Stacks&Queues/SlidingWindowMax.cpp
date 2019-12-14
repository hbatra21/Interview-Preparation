vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> ans;
    deque<int> q;
    int i = 0;
    while(i < B){
        while(!q.empty() && A[i] >= A[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        i++;
    }
    ans.push_back(A[q.front()]);
     while(i < A.size()){
        if(i - q.front() >= B){
            q.pop_front();
        }
        while(!q.empty() && A[i] >= A[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(A[q.front()]);
        i++;
    }
    return ans;
}
