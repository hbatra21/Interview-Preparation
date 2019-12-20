/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval A1,Interval A2){
    return A1.start<A2.start;
} 
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(),A.end(),compare);
    stack<Interval> st;
    vector<Interval> res;
    int n=A.size();
    st.push(A[0]);
    for(int i=1;i<n;i++){
        Interval temp = st.top();
        if(temp.end < A[i].start){
            st.push(A[i]);    
        } else if(temp.end < A[i].end) {
            temp.end = A[i].end;
            st.pop();
            st.push(temp);
        }
    }
    while (!st.empty()){
        Interval t = st.top();
        res.push_back(t);
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
