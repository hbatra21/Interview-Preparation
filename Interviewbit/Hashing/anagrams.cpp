vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> res;
    unordered_map<string, vector<int>>mp;
    string temp;
    for(int i = 0; i < A.size(); i++){
        temp = A[i];
        sort(temp.begin(), temp.end());
        mp[temp].push_back(i+1);
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        res.push_back(it->second);
    }
    return res;
}
