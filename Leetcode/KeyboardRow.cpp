class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> s1 = {'q','w','e','r','t','y','u','i','o','p' };
        set<char> s2 = {'a','s','d','f','g','h','j','k','l' };
        set<char> s3 = {'z','x','c','v','b','n','m' };
        vector<string> ans;
        for(auto word : words) {
            bool check = true;
            char temp = word[0];
            set<char> res;
            if(s1.find(tolower(temp)) != s1.end())
                res = s1;
            else if (s2.find(tolower(temp)) != s2.end())
                res = s2;
            else res = s3;
            for(char c : word) {
                if(res.find(tolower(c)) == res.end()){
                    check = false;
                    break;
                }
            
                    }
             if(check) ans.push_back(word);
           
        }
        
                   return ans;
                   }
};
