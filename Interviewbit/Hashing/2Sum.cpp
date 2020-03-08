vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int, int> mp;
    vector<int> ans;
            for (int i = 0; i < A.size(); i++) {
                int temp = B - A[i];
                if (mp.find(temp) != mp.end()) {
                    ans.push_back(mp[temp]);
                    ans.push_back(i + 1);
                    return ans;
                }
                if (mp.find(A[i]) == mp.end()) {
                    mp[A[i]] = i + 1;
                }
            }
            return ans;
        }
