class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int ans = 0; 
        int count = 0;
        for (int i=0; i<k; i++) 
            ans += arr[i];
        if(ans/k >= th)
            count++;
        int temp = ans; 
        for (int j = k; j < arr.size(); j++) { 
            temp = temp + arr[j] - arr[j-k];
            if(temp/k >= th)
                count++;
        } 
        return count;
    }
};
