class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int > ans;
        priority_queue<pair<int, int>>pq;
        int n = restaurants.size();
        if(veganFriendly){
            for(int i = 0; i <n; i++){
                if(restaurants[i][2] == 1 && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance){
                    pq.push(make_pair(restaurants[i][1], restaurants[i][0]));
                }
            }
        }
        else {
            for(int i = 0; i <n; i++){
                if(restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance){
                    pq.push(make_pair(restaurants[i][1], restaurants[i][0] ));
                }
            }
        }
        while(!pq.empty()){
            pair<int, int>p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};
