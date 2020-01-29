int Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int e1=INT_MAX,e2=INT_MAX;
    int count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(count1>0 && A[i]==e1){
            count1+=1;
        }
        else if(count2>0 && A[i]==e2){
            count2+=1;
        }
        else if(count1==0){
            e1=A[i];
            count1=1;
        }
        else if(count2==0){
            e2=A[i];
            count2=1;
        }
        else{
            count1--;
            count2--;
        }
    }
    if(count1==0 && count2==0)
        return -1;
    int freq=0;
    if(count1){
        for(int i=0;i<n;i++){
            if(A[i]==e1)
                freq++;
        }
        if(freq>n/3)
        return e1;
    }
    freq=0;
    if(count2){
        for(int i=0;i<n;i++){
            if(A[i]==e2)
                freq++;
        }
        if(freq>n/3)
            return e2;
    }
    return -1;
}
