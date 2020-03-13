class Solution {
public:
    int change(int amount, vector<int>& coins) {
		sort(coins.begin(),coins.end());
		int n=coins.size();
		vector<int> dp(amount+1);
		dp[0]=1;
		for(int i=0;i<n;i++){
			for(int j=1;j<=amount;j++){
				if(j>=coins[i]){
					 dp[j]+=dp[j-coins[i]];
				}          
			}
		}
		return dp[amount];  
	}
};
