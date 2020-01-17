class Solution {
public:
     long findSum(vector<int>& arr, long replace) {
        int sum=0;
        for(auto a: arr) {
            if(a > replace)
                sum+=replace;
            else
                sum+=a;
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        long low=0;
        long high= *max_element(arr.begin(), arr.end());
        while (low <= high) {
            long mid = low + (high-low)/2;
            long sum= abs(findSum(arr, mid));
            if(sum == abs(target)) return mid;
            else if (sum < abs(target))  low= mid+1;
            else high=mid-1;
        }
        long lsum=abs(abs(target)-abs(findSum(arr, low)));
        long hsum = abs(abs(target)-abs(findSum(arr, high)));
        return lsum < hsum? low:high;   
    }
};
