class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int ans = 0, d = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto ev : events){
            pq.push(make_pair(ev[0], ev[1]-ev[0]+1));
        }
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            if (p.first > d) 
                d = p.first;
            ans++;
            while (!pq.empty() && pq.top().first == d) {
                pair<int, int> tmp = pq.top();
                pq.pop();
                tmp.first++;
                if (--tmp.second) pq.push(tmp);
            }
            
            d++; 
        }
        return ans;
    }
};
