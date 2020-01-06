class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        set<int> s;
        int  n = arr.size();
        bool ans = true;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(s.find(it->second) == s.end()) {
                s.insert(it->second);
            }
            else {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
