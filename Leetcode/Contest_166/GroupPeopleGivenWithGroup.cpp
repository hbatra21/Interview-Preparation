class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int> > mp;
        for(int i = 0; i < groupSizes.size(); i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int> > res;
        for(auto m : mp){
            int size = m.first;
            int nums = m.second.size();
            vector<int> tmp;
            while(size-- && --nums >= 0){
                tmp.push_back(m.second[nums]);
                if(size == 0 && nums > size){
                    size = m.first;
                    res.push_back(tmp);
                    tmp.clear();
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
