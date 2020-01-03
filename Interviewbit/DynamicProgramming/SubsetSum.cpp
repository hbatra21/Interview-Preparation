// 2^n Approach (BruteForce- All possible subsets)
#include<bits/stdc++.h>
using namespace std;
int subsetSum(vector<int> v, int n, int sum) {
	if(sum == 0) return 1;
	if(n == 0 && sum != 0) return 0;
	if(v[n-1] > sum) return subsetSum(v, n-1, sum);
	return max(subsetSum(v, n-1, sum), subsetSum(v, n-1, sum - v[n-1]));
	
}
int main() {
	vector<int> v;
	int n, sum;
	cin >> n ;
	for(int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cin >> sum;
	int ans = subsetSum(v, n, sum);
	cout << ans << endl;
	return 0;
}

// Approach - 2 DP

#include <iostream>
using namespace std;
bool subsetSum(vector<int> arr, int n, int sum)
{ bool T[n + 1][sum + 1];
  for (int j = 1; j <= sum; j++)
		T[0][j] = false;
  for (int i = 0; i <= n; i++)
		T[i][0] = true;
  for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (arr[i - 1] > j)
				T[i][j] = T[i - 1][j];
			else
				T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i - 1]];
		}
	}
  return T[n][sum];
}
int main() {
	vector<int> v;
	int n, sum;
	cin >> n ;
	for(int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cin >> sum;
	bool ans = subsetSum(v, n, sum);
	cout << ans << endl;
	return 0;
}
