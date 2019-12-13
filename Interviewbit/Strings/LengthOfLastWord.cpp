int Solution::lengthOfLastWord(const string A) {
    int i = A.length() - 1;
    while(i >= 0 && A[i] == ' '){
        i--;
    }
    int res = 0;
    while(i >= 0){
        if(A[i] == ' '){
            return res;
        }
        res++;
        i--;
    }
    return res;
}
