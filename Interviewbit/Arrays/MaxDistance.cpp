int Solution::maximumGap(const vector<int> &num) {
    if (num.size() == 0) return -1;
        if (num.size() == 1) return 0;
        vector<pair<int, int> > v; 
        for (int i = 0; i < num.size(); i++) {
            v.push_back(make_pair(num[i], i));
        }
            sort(v.begin(), v.end());
            int len = v.size();
            int maxIndex = v[len - 1].second;
            int ans = 0;
            for (int i = len - 2; i >= 0; i--) {
                ans = max(ans, maxIndex - v[i].second);
                maxIndex = max(maxIndex, v[i].second);
            }
            return ans;
    }
