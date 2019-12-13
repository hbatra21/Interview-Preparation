string Solution::countAndSay(int A) {
    int n;
    if(A==1) return "1";
    if(A==2) return "11";
    string str="11";
    for(int i=3;i<=A;i++){
        str+='$';
        int len=str.length();
        int cnt=1;
        string tmp="";
        for (int j = 1; j < len; j++) 
        {   if (str[j] != str[j-1]) 
            { 
                 tmp += cnt + '0'; 
                 tmp += str[j-1]; 
                 cnt = 1; 
            } 
            else cnt++; 
        } 
        str = tmp; 
    } 
    return str; 
}
