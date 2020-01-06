class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map <char, int> hash1;
        //unordered_set <string> hash2;
        int n = J.length();
        int m = S.length();
        int count = 0;
        for (int i = 0; i < m; i++) {
                hash1[S[i]]++;
        }
        
        for (int i = 0; i < n; i++) {
            char temp = J[i];
            if(hash1.find(temp) != hash1.end() ) {
                count += hash1[temp];
            }
        }
        return count;
    }
};
