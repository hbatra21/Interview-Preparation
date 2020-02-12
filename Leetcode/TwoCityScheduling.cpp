class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < costs.size(); i++){
            pq.push(make_pair(costs[i][0] - costs[i][1], i));
        } 
        int city1 = 0, city2 = 0;
        for(int i = 0; i < costs.size() / 2; i++) {
           int idx = pq.top().second;
            city1 += costs[idx][0];
            pq.pop();
        }
        for(int i = 0; i < costs.size() / 2; i++) {
             int idx = pq.top().second;
            city2 += costs[idx][1];
            pq.pop();
        }
        return city1 + city2;
    }
};
