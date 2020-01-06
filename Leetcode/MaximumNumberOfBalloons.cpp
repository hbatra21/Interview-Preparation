class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string word = "balloon";
        int ans = 0;
        map<char, int> mp;
        for (auto c : text) {
            mp[c]++;
        }
        while(1) {
            for(auto c : word){
                if(mp[c] >= 1) 
                    mp[c]--;
                else 
                    return ans;
            }
            ans++;
        }
        
    }
};
