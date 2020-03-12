vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    vector<int> v(heights.size(), -1);
    map<int, int> mp;
    for(auto i=0; i<heights.size(); i++){
        mp[heights[i]] = infronts[i];
    }
    for(auto it : mp){
        int i = 0, j = 0;
        while(i != it.second) {
            if(v[j] == -1)
                i++;
            j++;
        }
        while(v[j] != -1) {
            j++;
        }
        v[j] = it.first;
    }
    return v;
}
