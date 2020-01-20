class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        deque<int> dq;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dq.push_back(grid[i][j]);
            }
        }
        for(int i = 0; i < k; i++){
            int p = dq.back();
            dq.pop_back();
            dq.push_front(p);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = dq.front();
                dq.pop_front();
            }
        }
        return grid;
    }
}; 


// Approach 2
class Solution {
public:
vector<vector> shiftGrid(vector<vector>& grid, int k) {
    int n=grid.size(),m=grid[0].size(),temp;
    while(k--){
      int i=n-1,j=m-1;
      temp=grid[i][j];
    for(int t=1;t<n*m;t++)
    if(j==0){
        j=m-1;
        grid[i][0]=grid[i-1][j];
        i=i-1;
    }
    else{
        grid[i][j]=grid[i][j-1];
        j=j-1;
    }
    grid[0][0]=temp;   
    }
    return grid;
}
};
