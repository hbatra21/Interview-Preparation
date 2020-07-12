int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<int>vis(100, 0);
    queue<int>q;
    q.push(0);
    vis[0] = 1;
    int steps = 0;
    vector<int>moves(100, -1);
    for(int i = 0; i < A.size(); i++){
        moves[A[i][0]-1] = A[i][1]-1;    
    }
    for(int i = 0; i < B.size(); i++){
        moves[B[i][0]-1] = B[i][1]-1;    
    }
    while(!q.empty()){
        int n = q.size();
        while(n--){
            int v = q.front();
            q.pop();
            if(v == 99) return steps;
            for(int i = v+1; i <= v+6 && i <= 99; i++){
                if(!vis[i]) {
                    vis[i]=1;
                    if(moves[i] == -1)
                        q.push(i);
                    else q.push(moves[i]);
                }
            }
        }
        steps++;
    }
    return -1;
}
