class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, int> temp;
        vector<pair<int, int> > ans;
        vector<int> t;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    temp[i]++;
                }
            }
            ans.push_back(make_pair(temp[i], i));
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < k; i++){
            t.push_back(ans[i].second);
        }
        return t;
        
    }
};
/*class Solution {
public:
  static bool myComp(pair<int, int>& a, pair<int, int>& b)
    {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        vector<pair<int,int>> index;
        for(int i=0; i<mat.size(); i++) {
            int j = 0;
            while(j < mat[i].size() && mat[i][j] == 1)
                j++;
            index.push_back({j+1, i});
        }   
        sort(index.begin(), index.end(), myComp);
        for(int i=0; i<k; i++)
            res.push_back(index[i].second);
        return res;
    }
};
*/
