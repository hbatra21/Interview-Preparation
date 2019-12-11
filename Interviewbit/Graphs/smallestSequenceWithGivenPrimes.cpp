vector<int> Solution::solve(int A, int B, int C, int D) {
    set <int>s;
    vector<int >v;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    int ctr = 0;
    while(ctr<D)
    {
        auto i = s.begin();
        v.push_back(*i);
        s.insert((*i)*A);
        s.insert((*i)*B);
        s.insert((*i)*C);
        s.erase(i);
        ctr++;
    }
    return v;
}
