int Solution::evalRPN(vector<string> &A) {
    stack<int> st;
    int n = A.size();
    for(int i = 0; i < n; i++) {
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/"){
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            if(A[i] == "+"){
                st.push(second+first);
            }
            else if(A[i] == "-"){
                st.push(second-first);
            }
            else if(A[i] == "*"){
                st.push(second*first);
            }
            else{
                st.push(second/first);
            }
        }
        else{
            st.push(atoi(A[i].c_str()));
        }
    }
    return st.top();
}