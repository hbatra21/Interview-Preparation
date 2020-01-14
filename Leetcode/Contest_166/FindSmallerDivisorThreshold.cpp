class Solution {
public:
bool isPossible(const vector<int> &nums, int divisor, int threshold) {
        int sum = 0;
        for (auto dividend: nums) {
            sum += ceil((double)dividend/divisor);
        }
        
        return sum <= threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = pow(10, 9), mid, answer = INT_MAX;
        
        while (low <= high) {
            mid = (low + high) >> 1;
            if (isPossible(nums, mid, threshold)) {
                answer = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }    
        return answer;
    }
};
