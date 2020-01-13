class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>&           containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;
        queue<int> q;
        vector<int> visited(status.size(), 0);
        for(int i : initialBoxes) {
            q.push(i);
        }
        while(!q.empty()) {
            int len = q.size();
            bool open = false;
            for(int i = 0; i < len; i++) {
                if(status[q.front()] == 1)
                    open = true;
                q.push(q.front());
                q.pop();
            }
            if(open == false)
                break;
            for(int i = 0; i < len; i++) {
                if(status[q.front()]==1){
                    ans+=candies[q.front()];
                    for(int j = 0; j < containedBoxes[q.front()].size(); j++)
                        q.push(containedBoxes[q.front()][j]);
                    for(int j = 0; j < keys[q.front()].size(); j++)
                        status[keys[q.front()][j]]=1;
                    q.pop();
                }
                else
                {
                    q.push(q.front());
                    q.pop();
                }
            }
        }
        return ans;
    }
};
