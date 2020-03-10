class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
       //  sort(clips.begin(), clips.end());
       //  vector<int> dp(100);
       //  for(auto clip : clips)
       //      dp[clip[0]] = clip[1];
       //  int count = 1;
       //  int start = 0, end = dp[0];
       //  while (start < T && end < T) {
       //      int maxi = 0, maxIndex = -1;
       //      for (int j = end; j > start; j--) {
       //          if (dp[j] > maxi) {
       //              maxi = dp[j];
       //              maxIndex = j;
       //          }
       //      }
       //      if (maxIndex == -1 || maxi <= end) return -1;
       //      count++;
       //      start = maxIndex;
       //      end = dp[start];
       //  }
       //  return count;
       // }
        vector<int> dp(101, 101);
        dp[0] = 0;
        for (auto& c : clips)
            for (int i = c[0] + 1; i <= c[1]; i++)
                dp[i] = min(dp[i], dp[c[0]] + 1);
        return dp[T] >= 100 ? -1 : dp[T];
    }
};
