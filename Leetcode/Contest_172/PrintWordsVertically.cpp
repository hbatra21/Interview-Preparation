class Solution 
{
public:
    vector<string> printVertically(string s) 
    {
        vector<string> l;
        string tmp;    
        int maxLen = numeric_limits<int>::min();
        
        for (char t : s)								// Vectorize all space separated strings 
        {		
            if (t == ' ' && tmp.length() >= 1)
            {
                l.push_back(tmp);
                tmp = "";
            }
            else if (t != ' ')
                tmp += t;
        }

        if (tmp.length() >= 1)
            l.push_back(tmp);
        
        for(auto str : l)
        {
            maxLen = std::max(maxLen, (int)str.length());	// Find max length which will be the LENGTH of the final list of strings !
        }
        
        vector<string> res(maxLen, "");
        int j = 0, k = 0;
		
        while(j < maxLen)									// Outer loop is FOR each 'j'the character in INNER LOOP's 'i'th string 
        {           
            for(int i = 0; i < l.size(); i++)				// Loop through each string in the list and add the 'j'th character
            {
                if(j < l[i].length())   
                    res[j] += l[i][j];
                else 
                    res[j] += ' ';
            }
			
            size_t end = res[j].find_last_not_of(' ');		// Trim all TRAILING spaces 
            
	        if(end != std::string::npos) 
                res[j] = res[j].substr(0, end + 1);
            
            j++;
        }
        
        return res;
    }
};
