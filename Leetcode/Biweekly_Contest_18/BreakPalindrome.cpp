class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        string s = "";
        if(n == 0)
            return "a";
        if(n == 1)
            return s;
        for(int i = 0; i < n/2; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a'; 
                return palindrome;
            }
        }
        palindrome[n-1] = 'b';
        return palindrome;
            
        
    }
};
