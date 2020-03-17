class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        unordered_map<int,list<int>>adjlist;
        for(int i=0;i<paths.size();i++) {
            adjlist[paths[i][0]].push_back(paths[i][1]);
            adjlist[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int>res;
        unordered_map<int,int>color;
        for(int i=1;i<=N;i++){
            int node=i;
            for(int col=1;col<=4;col++){
                bool found=false;
                for(int neighbour:adjlist[node]){
                    if(color[neighbour]==col)   {
                        found=true;
                        break;
                    }
                }
                if(found==false){
                    color[node]=col; 
                    res.push_back(col);
                    break;
                }
            }
        }
    return res;    
    }
};
