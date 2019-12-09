vector<int> Solution::dNums(vector<int> &A, int B) {
     vector<int> ans;
    if(B > A.size())
        return ans;
    map<int ,int> mp;
    int count = 0;
    for(int i = 0; i < B; i++){
        if(mp.find(A[i]) == mp.end()){
            mp[A[i]] = 1;
            count++;
        }
        else{
            mp[A[i]]++;
        }
    }
    ans.push_back(count);
    for(int i = B; i < A.size(); i++){
        auto it = mp.find(A[i - B]);
        if(it->second == 1){
            mp.erase(it);
            count--;
        }
        else it->second--;
        auto it1 = mp.find(A[i]);
        if(it1 != mp.end()){
            it1->second++;
        }
        else {
            mp[A[i]] = 1;
            count++;
        }
        ans.push_back(count);
    }
    
    return ans;
}
