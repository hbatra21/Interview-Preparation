stack<int>st;
stack<int> min_st;
MinStack::MinStack() {
    while(!st.empty()){
        st.pop();
    }
    while(!min_st.empty()){
        min_st.pop();
    }
}
void MinStack::push(int x) {
    st.push(x);
    if(min_st.size() == 0) min_st.push(x);
    else {
        if(x <= min_st.top()){
            min_st.push(x);
        }
        else{
            min_st.push(min_st.top());
        }
    }
}

void MinStack::pop() {
    if(st.size() != 0) {
        st.pop();
        min_st.pop();
    }
}

int MinStack::top() {
    if(st.size() == 0)
      return -1;
    return st.top();
}

int MinStack::getMin() {
    if(min_st.size() == 0) 
      return -1;
    return min_st.top();
}

