int isStep(long long int num) {
    int prev = -1;
    while(num) {
        int curr = num % 10;
        if(prev == -1) prev = curr;
        else {
            if(abs(prev - curr) != 1) return 0;
        }
        prev = curr;
        num /= 10;
    }
    return 1;
}
vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;
    if(A>B) return ans;
    for(long long int i = A; i <= B; i++){
        if(isStep(i))
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
