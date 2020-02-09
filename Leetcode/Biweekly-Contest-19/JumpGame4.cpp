// Dp won't work as we need to step back also and we can take as many steps back as possible
// DP CODE Passed (21/26) cases
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        if(n == 1)
            return 0;
        if(n == 2)
            return 1;
        vector<int> dp(n, 100000002);
        dp[0] = 0;
        // for(int i = 1; i < n; i++){
        //     for(int j = 0; j < i; j++){
        //         if(arr[i] == arr[j]){
        //             dp[i] = min(dp[i], dp[j]+1);
        //             //cout<<dp[i]<<" ";
        //         }
        //         else {
        //             dp[i] = min(dp[i], dp[i-1]+1);
        //             //cout<<dp[i]<<" ";
        //             }
        //         }
        //    // cout<<dp[i]<<" ";
        // }
        // for(int i = 1; i < n-1; i++){
        //     dp[i] = min(dp[i], min(dp[i+1], dp[i-1])+1);
        //     //cout<<dp[i]<<" ";
        // }
        // dp[n-1] = min(dp[n-1], dp[n-2]+1);
        // for(int i = 1; i < n; i++){
        //     for(int j = 0; j < i; j++){
        //         if(arr[i] == arr[j]){
        //             dp[i] = min(dp[i], dp[j]+1);
        //             //cout<<dp[i]<<" ";
        //         }
        //         else {
        //             dp[i] = min(dp[i], dp[i-1]+1);
        //             //cout<<dp[i]<<" ";
        //             }
        //         }
        //     //cout<<dp[i]<<" ";
        // }
        // return dp[n-1];
        for( int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(arr[i]==arr[j]){
					dp[i]=min(dp[i],dp[j]+1);
				}
				else if(arr[i]!=arr[j]) {
					if(j!=0 && arr[i]==arr[j-1]) {
						dp[i]=min(dp[i],dp[j]+2);
					}
					if(j!=i-1 && arr[i]==arr[j+1]) {
						dp[i]=min(dp[i],dp[j]+2);
					}  
				}
			}
			dp[i]=min(dp[i],dp[i-1]+1);
			if(i!=n-1) 
                dp[i]=min(dp[i],dp[i+1]+1);
		}
		return dp[n-1];
    }
};

// BFS MODIFIED SOLUTION

constexpr int MAX_SIZE = 5e4;

int minJumps(vector<int> const& arr) {
  int const N = arr.size();

  // Handle trivial case
  if (N == 1)
    return 0;

  // Build inverse of arr (skip index 0)
  unordered_map<int, vector<int>> inverse;
  for (int i = 1; i < N; ++i)
    inverse[arr[i]].push_back(i);

  // BFS
  queue<int> q;
  q.push(0);
  bitset<MAX_SIZE+1> visited;
  visited[0] = true;
  for (int result = 1; !q.empty(); ++result) {
    int size = q.size();
    while (size--) {
      int i = q.front();
      q.pop();

      auto processNext = [&](int j){
        if (j == N-1)
          return true;
        if (j >= 0 && j < N && !visited[j]) {
          visited[j] = true;
          q.push(j);
        }
        return false;
      };

      if (processNext(i+1) || processNext(i-1))
        return result;
      for (int j : inverse[arr[i]])
        if (j != i && processNext(j))
          return result;
      inverse[arr[i]].clear();
    }
  }

  assert(false);
}
