string Solution::solve(string A) {
    string temp = "";
    stack <string> st;
    int n = A.length();
    for (int i = 0; i < n; i++) {
        if (A[i] != ' ' ) {
            while (i < n && A[i] != ' ') {
                temp += A[i];
                i++;
            }
            st.push(temp);
            temp = "";
        }
    }
    temp = "";
    while (st.size() != 1) {
        temp += st.top();
        st.pop();
        temp += " ";
    }
    temp += st.top();
    return  temp;
}
