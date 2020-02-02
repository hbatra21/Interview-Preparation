class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int sizeSoFar = 0;
        int res = 0;
        unordered_map<int, int> freq;
        for(int i : arr)
            freq[i]++;
        priority_queue<int> pq;
        for(auto& i : freq)
            pq.push(i.second);
        while(!pq.empty() && sizeSoFar < n/2)
        {
            int curr = pq.top();
            pq.pop();
            
            sizeSoFar += curr;
            res++;
        }
        return res;
    }
};
