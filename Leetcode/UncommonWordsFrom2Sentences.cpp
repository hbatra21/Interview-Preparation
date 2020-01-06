class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int>s;
        vector<string> v;
        stringstream ss(A);
        
        while(ss >> A)
            s[A]++; 
        stringstream ss1(B);
        while(ss1 >> B)
          s[B]++; 
        for (auto i: s)
            if(i.second==1)
               v.push_back(i.first);
        return v;
    
    }
};
