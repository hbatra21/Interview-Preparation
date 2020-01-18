class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        if(num == 0)
            return dp;
        dp[0] = 0;
        dp[1] = 1;
        int powerOfTwo = 2;
        for(int i = 2; i <= num; ++i){
            if(i == powerOfTwo) {
                dp[i] = 1;
                powerOfTwo = powerOfTwo << 1;
            }
            else{
                int idx = i - (powerOfTwo >> 1);
                dp[i] = 1 + dp[idx];
            }          
        }
        return dp;        
    }
};
