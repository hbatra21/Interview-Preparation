class Solution {
public:
    string removeOuterParentheses(string S) {
        int n = S.length(), count = 0;
        string ans = "";
        stack<char> st;
        if(n == 2)
            return ans;
        for(int i = 0; i < n; i++){
            char c = S[i];
            if(c == '('){
                count++;
                st.push(c);
                if(count != 1){
                    ans += c; 
                }  
            }
            else {
                if(c == ')'){
                    if(st.size() != 1)
                       ans += c;;
                    st.pop();
                }
            }
            if(st.empty()){
                count = 0;
            }
        }
        return ans;  
    }
};
