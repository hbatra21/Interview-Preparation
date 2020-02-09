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

int minJumps(vector<int>& arr) {
        queue<pair<int, int>> q;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]].push_back(i);
        int n = arr.size();
        vector<int> vis(n, false);
        q.push({ n - 1, 0 });
        vis[n - 1] = 1;
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
			int f = q.front().first;
			int steps = q.front().second;
			q.pop();
			if(f == 0)
				return steps;
			if(f - 1 >= 0 && !vis[f - 1]) {
				q.push({ f - 1, steps + 1 });
				vis[f - 1] = true;
			}
			if(f + 1 < n && !vis[f + 1]) {
				q.push({ f + 1, steps + 1 });
				vis[f + 1] = true;
			}
			for(auto j : mp[arr[f]]) {
				if(j == f)
					continue;
				if(!vis[j]) {
					vis[j] = true;
					q.push({ j, steps + 1 });
				}
			}
        }
        return -1; 
    }
