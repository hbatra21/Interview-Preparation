int countServers(vector<vector<int>>& grid) {
        vector<int> row(grid.size(), 0), column(grid[0].size(), 0);
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    row[i]++;
                    column[j]++;       
                }
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1 && (row[i] > 1 || column[j] > 1)){
                    count++;
                }
            }
        }
        return count;
    }
