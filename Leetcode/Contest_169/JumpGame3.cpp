class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
    queue<int> que;
        que.push(start);
        while (!que.empty()) {
            int top = que.front();
            que.pop();
            if (top < 0 || top >= arr.size() || arr[top] == -1) 
                continue;
            if (arr[top] == 0) {
                return true;
            } else {
                que.push(top + arr[top]);
                que.push(top - arr[top]);
            }
            arr[top] = -1;
        }
        return false;
    }
};
