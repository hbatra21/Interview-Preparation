class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> hash;
        int ans = 0;
        for (int i = 0; i < chars.length(); i++) {
            hash[chars[i]]++;
        }
        for(auto word : words) {
            unordered_map<char, int> hash1 = hash;
            bool flag = true;
            int i;
            for( i = 0; i < word.length(); i++) {
                if(hash1.find(word[i]) != hash1.end() && --hash1[word[i]] >= 0) {
                    
                }
                else{
                    break;  
                }
                }
            if(i == word.length()) 
              ans += word.length();
        }
        return ans;
    }
};
