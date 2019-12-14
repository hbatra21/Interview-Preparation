int Solution::braces(string A) {
    stack<char>st;
    int i,count=0;
    int n=A.length();
    for(i=0;i<n;i++){
        if(A[i]==')'){
            count=0;
            char tp=st.top();
            st.pop();
            if(tp=='(')
              return 1;
            else{
                while(tp!='('){
                    tp=st.top();
                    st.pop();
                    count++;
                }
                if(count==1)
                  return 1;
            }
        }
        else{
            st.push(A[i]);
        }
    }
    return 0;
}
