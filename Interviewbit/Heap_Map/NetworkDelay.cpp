typedef pair<int, int> pi;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& v, int n, int k) {
        vector<pi> graph[n+1];
        vector<int> vis(n+1, 0);
        for(int i = 0; i < v.size(); i++)
            graph[v[i][0]].push_back(make_pair(v[i][1], v[i][2]));
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        const int inf=1e9;
        vector<int>dist(n+1,inf);
        dist[k]=0;
        pq.push(make_pair(0,k));
        int u,vv,w;
        while(!pq.empty()){
            pi top = pq.top();
            pq.pop();
            u = top.second;
            if(vis[u])
                continue;
            for(auto i : graph[u]){
                vv = i.first;
                w = i.second;
                if(dist[vv] > dist[u] + w) {
                    dist[vv] = dist[u] + w;
                    pq.push(make_pair(dist[vv],vv));
                }
            }
            vis[u] = 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,dist[i]);
        if(ans==inf)
            return -1;
        return ans;
    }
};
