class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans(arr.size());
        int rank = 1;
        map<int, vector<int>> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]].push_back(i); 
        }
        for(auto i : mp){
            for(int pos:i.second){
                ans[pos] = rank;
            }
            rank++;
        }
        return ans;
    }
};
