class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int> a(nums.begin(),nums.end());
        while(!a.empty()) {
            int top = *a.begin();
            for (int i = 0; i < k; ++i) {
                auto iter = a.find(top + i);
                if (iter == a.end()) 
                    return false;
                a.erase(iter);
            }
        }
        return true;
    }
};
