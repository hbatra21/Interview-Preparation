class Solution {
public:
    
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        int st = 0, en = n - 1;
        int mid = st + (en - st)/2;
        while (st <= en) {
            mid = st + (en - st)/2;
            if(A[mid] < A[mid-1]) {
                en = mid-1;
            }
            else if ( A[mid] < A[mid + 1])
                st = mid + 1;
            else {
                ans = mid;
                break;
            }
        }
        return ans;
    }
};
