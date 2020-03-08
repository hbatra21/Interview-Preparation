vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, pair<int, int>> mp; 
    for (int i = 0; i < n-1; i++) 
        for (int j = i+1; j < n; j++) 
            mp[A[i] + A[j]] = {i, j};
    for (int i = 0; i < n-1; i++)  { 
        for (int j = i+1; j < n; j++) { 
            int sum = A[i] + A[j]; 
            if (mp.find(X - sum) != mp.end()) { 
  
                // Making sure that all elements are 
                // distinct array elements and an element 
                // is not considered more than once. 
                pair<int, int> p = mp[X - sum]; 
                if (p.first != i && p.first != j && 
                        p.second != i && p.second != j) 
                { 
                    cout << arr[i] << ", " << arr[j] << ", "
                         << arr[p.first] << ", "
                         << arr[p.second]; 
                    return; 
                } 
            } 
        } 
    }
}

/*vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    int n = A.size();
    for(int i = 0; i < n-3; i++) {
        if(i > 0 && A[i] == A[i-1]) continue;
        for(int j = i+1; j < n-2; j++){
            if(j>i+1 && A[j] == A[j-1]) continue;
            int l = j+1, r = n-1;
            while(l < r){
                int sum = A[i]+A[j]+A[l]+A[r];
                if(sum == B){
                    vector<int> temp;
                    temp.emplace_back(A[i]);
                    temp.emplace_back(A[j]);
                    temp.emplace_back(A[l]);
                    temp.emplace_back(A[r]);
                    res.emplace_back(temp);
                    l++;
                    while(l < r && A[l] == A[l-1])
                        l++;
                }
                else if(sum > B) r--;
                else if(sum < B) l++;
            }
        }
    }
    return res;
}
*/
