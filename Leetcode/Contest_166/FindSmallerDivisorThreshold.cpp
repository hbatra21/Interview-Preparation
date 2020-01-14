class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
    vector <int> v;
		int ans = 0;
		for (int i = 1; i <= threshold; i++) {
			v.push_back(i);
		}
		int l = 0, r = v.size()-1;

		while (l <= r) {
			int mid = l + (r - l) / 2;
			long long int sum = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] % v[mid] == 0) {
					sum += (nums[i] / v[mid]);
				} else{
					sum += (nums[i] / v[mid]) + 1;
				}
			}

			if (sum > threshold) {
				l = mid + 1;
			} else {
				ans = v[mid];
				r = mid - 1;
			}
		}

		return ans;
    }
};
