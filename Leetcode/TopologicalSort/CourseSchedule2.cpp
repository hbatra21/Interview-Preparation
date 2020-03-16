class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>>adj(num, vector<int>());
        vector<int>degree(num, 0);
        vector<int> res;
        for(auto p : pre){
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        queue<int>q;
        for(int i = 0; i < num; i++)
            if(degree[i] == 0)
                q.push(i);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto i : adj[curr]){
                if(--degree[i] == 0)
                    q.push(i);
            }
        }
        if(res.size() == num)
            return res;
        else return vector<int>();
    }
};
