class Solution {
public:
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<pair<int, int>>> graph(n);
//         for (int i=0; i<edges.size(); i++) {
//             graph[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
//             graph[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
//         }
//         vector<int> neighbors;
//         int minCount = INT_MAX;
//         for (int i=0; i<n; i++) {
//             unordered_set<int> canVisit;
//             dfs(graph, canVisit, distanceThreshold, i);
//             int count = canVisit.size() - 1;
//             minCount = min(minCount, count);
//             neighbors.push_back(count);
//         }
//         vector<int> minNeighborCities;
//         for (int i=0; i<neighbors.size(); i++) {
//             if (neighbors[i] == minCount) {
//                 minNeighborCities.push_back(i);
//             }
//         }
//         return minNeighborCities.back();
//     }
    
//     void dfs(vector<vector<pair<int, int>>>& graph, unordered_set<int>& canVisit, int distance, int start) {
//         if (distance < 0) {
//             return;
//         }
//         canVisit.insert(start);
//         for (int i=0; i<graph[start].size(); i++) {
//             if (canVisit.find(graph[start][i].first) == canVisit.end()) {
//                 int cost = graph[start][i].second;
//                 dfs(graph, canVisit, distance-cost, graph[start][i].first);
//             }
//         }
//     }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0 ; i < n ; ++i) {
            dp[i][i] = 0;
        }
        
        for (const auto& e : edges) {
            int s = e[0];
            int d = e[1];
            int c = e[2];
            dp[s][d] = c;
            dp[d][s] = c;
        }
        
        for (int k = 0 ; k < n ; ++k) {
            for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < n ; ++j) {
                    if (dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
        
        int min = INT_MAX;
        vector<int> counts(n, 0);
        for (int i = 0 ; i < n ; ++i) {
            int count = 0;
            for (int j = 0 ; j < n ; ++j) {
                if (i == j) {
                    continue;
                }
                if (dp[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            min = std::min(min, count);
            counts[i] = count;
        }
        
        for (int i = n - 1 ; i >= 0 ; --i) {
            if (counts[i] == min) {
                return i;
            }
        }
        
        return -1;
    }
};
