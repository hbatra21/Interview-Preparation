class Solution {
public:
    void bfs(string S, int pos , vector<string> &v, string cur) {
        if(pos == S.length()) {
            v.push_back(cur);
            return;
        }
        if(isalpha(S[pos])) {
            bfs(S, pos+1, v, cur+(char)tolower(S[pos]));
            bfs(S, pos+1, v, cur+(char)toupper(S[pos]));
        }
        else {
            bfs(S, pos+1, v, cur + (S[pos]));
        }
        
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> v;
        bfs(S, 0, v, "");
        return v;    
    }
};
