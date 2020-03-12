class Solution {
public:
    void dfs(string digits, int start, string &path, vector<string> &res, vector<string> &letter){
        if(start == digits.length()){
            res.push_back(path);
            return ;
        }
        for(auto c: letter[digits[start] - '0']){
            path.push_back(c);
            dfs(digits, start + 1, path, res, letter);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0)
            return res;
        vector<string>letter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string path = "";
        dfs(digits, 0, path, res, letter);
        return res;
    }
};
