class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);
        res[n-1] = -1;
        int maxi = arr[n-1];
        for(int i = n-2; i >= 0; i--) {
            res[i] = maxi;
            maxi = max(maxi, arr[i]);
        }
        return res;
    }
};
