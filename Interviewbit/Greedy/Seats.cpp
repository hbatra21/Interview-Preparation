   #define MOD 10000003
int Solution::seats(string A) {
    int n = A.length();
    /*int count = 0, maxCount = 0;
    int start, index, end, hops = 0;
    for(int i = 0; i < n; i++){
        count = 0;
        index = i;
        while(A[i] == 'x' && i < n){
            i++;
            count++;
        }
        if(maxCount < count){
            maxCount = count;
            start = index;
            end = i-1;
        }
    }
    //cout<<maxCount<<" "<<start<<" "<<end<<" "<<endl;
    int f1 = start, f2 = end;
    for(int j = 0; j < n; j++){
        if (A[j] == 'x' && !(j >= f1 && j <= f2))
        {
            int d1 = abs(start - 1 - j);
            int d2 = abs(end + 1 - j);
            if (d1<=d2)
                if (start > 0)
                    --start;
            else
                if (end < n-1)
                    ++end;
            hops += min (d1, d2);
        }
    }
    return hops % 10000003;
    */
    vector<int> pos;
    for (auto i = 0; i<n; ++i)
        if (A[i] == 'x')
            pos.emplace_back(i);
    
    auto psize = pos.size();
    
    if (psize == 0)
        return 0;
    int mid = psize/2;
    int median = psize & 1 ? pos[mid] : (pos[mid-1] + pos[mid])/2;
    
    int hops = 0; 
    int empty = A[median] == 'x' ? median - 1 : median;
    
    for (auto s = median-1; s>=0; --s)
        if (A[s] == 'x')
        {
            hops += empty - s;
            hops %= MOD;
            --empty;
        }
            
    empty = median + 1;
    for (auto e = median+1; e<n; ++e)
        if (A[e] == 'x')
        {
            hops += e - empty;
            hops %= MOD;
            ++empty;
        }
    
    return hops % MOD;

}
