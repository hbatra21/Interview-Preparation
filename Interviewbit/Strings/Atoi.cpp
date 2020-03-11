int Solution::atoi(const string str) {
    long long int res = 0;
        string temp = str;
        bool sign = false;
        while(temp[0] == ' ')
            temp.erase(temp.begin());
        if(temp[0] == '-' || temp[0] == '+'){
            if(temp[0] == '-')
                sign = true;
            temp.erase(temp.begin());
        }
        for(char ch : temp){
            if(!(ch >= '0' && ch <= '9'))
                break;
            res = res*10 + (ch-'0');
            if(res > INT_MAX)
                return (sign ? INT_MIN : INT_MAX);
        }
        if(sign)
            res = -1*res;
        return res;
}
