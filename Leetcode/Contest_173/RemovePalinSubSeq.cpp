class Solution {
public:
    int isPalin(string s){
        int l = 0; 
        int h = s.length() - 1; 
        while (h > l) 
            if (s[l++] != s[h--]) 
            return 0; 
  
    return 1; 
    }
    int removePalindromeSub(string s) {
        if(s.length() == 0) 
            return 0; 
        if (isPalin(s)) 
            return 1; 
  
        return 2;    
    }
};
