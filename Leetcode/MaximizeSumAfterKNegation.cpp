class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        for (int i = 0; K > 0 && i < A.size() && A[i] < 0; ++i, --K)
            A[i] = -A[i];
        return accumulate(A.begin(), A.end(), 0) - (K%2) * *min_element(A.begin(), A.end()) * 2;
    }
    //     priority_queue<int, vector<int>, greater<int>> pq;
    //     int n = A.size();
    //     int sum = 0;
    //     for(int i = 0; i < n; i++){
    //         pq.push(A[i]);
    //     }
    //     while(k--){
    //         int top = pq.top();
    //         pq.pop();
    //         top = (-1)*top;
    //         pq.push(top);
    //     }
    //     while(!pq.empty()){
    //         int top = pq.top();
    //         pq.pop();
    //         sum += top;
    //     }
    //     return sum;
    // }
};
