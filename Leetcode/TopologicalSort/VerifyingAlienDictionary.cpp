class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mp;
        for(int i = 0; i < order.length(); i++) {
            mp[order[i]] = i;
        }
        for(int i = 0; i < words.size() - 1; ++i ) {
            string word1 = words[i];
            string word2 = words[i+1];
            bool flag = false;
            for (int k = 0; k < min(word1.length(), word2.length()); ++k) {
                if (word1[k] != word2[k]) {
                    if (mp[word1[k]] > mp[word2[k]])
                        return false; 
                    flag = true;
                    break;
                }
            }
              if (word1.length() > word2.length() && flag == false)
                  return false;
        }
        return true;
    }
};
