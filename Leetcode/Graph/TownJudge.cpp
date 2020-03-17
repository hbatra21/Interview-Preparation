class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> arr (N+1, 0);
		for (auto& v : trust)
			arr[v[1]]++, arr[v[0]]--; 
		for (int i = 1; i <= N; i++)
			if (arr[i] == N-1) return i;
		return -1;
    }
};
