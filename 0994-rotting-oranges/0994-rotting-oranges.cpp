class Solution {
public:
vector<pair<int,int>>direction={{0,1},{1,0},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        //using DFS 
          //count all fresh oranges 
          int freshOrange=0;
          int n=grid.size();
          int m=grid[0].size();
          queue<pair<int,int>>q;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    freshOrange++;
                }
            }
         }
      if(freshOrange == 0)
            return 0;
        int time=0;
        int rotton=0;
        while(!q.empty()){
            int size=q.size();
         for(int i=0;i<size;i++){
           auto indexes=q.front();
           q.pop();
           int i_=indexes.first;
           int j_=indexes.second;
           //check validations 
           for(auto dir:direction){
            int ni=i_+dir.first;
            int nj=j_+dir.second;
            //check validations 
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                grid[ni][nj]=2;
                q.push({ni,nj});
                rotton++;
            }
           }
         }
           time++;
        }
        
       return freshOrange==rotton ?time-1:-1;
    }
};