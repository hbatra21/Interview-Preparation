bool isCycle(int v, int A, vector<int> &B, vector<int> &C, vector<int> &color){
     if(color[v]==0){
          color[v]=1;
        for(int i=0; i<B.size(); i++){
            if(B[i]==v){
                 if(color[C[i]]==1){
                    
                    return true;
                } 
                if(isCycle(C[i], A, B, C,color)){
                   
                    return true;
                }
            }
        }
     }
    color[v]=2;
    return false;
}
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
  
    vector<int> color(A+1, 0);
     
    bool ans = false;
    for(int i=1; i<=A; i++){
        if(!color[i])
         ans = isCycle(i,A, B, C,color);
        
         if(ans) return 0;
    }
    return ans?0:1;
}
