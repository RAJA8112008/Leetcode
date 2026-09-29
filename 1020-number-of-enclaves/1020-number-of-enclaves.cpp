class Solution {
public:
   vector<pair<int,int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
   void dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
     grid[i][j]=0;
      for(auto dir:directions){
        int ni=dir.first+i;
        int nj=dir.second+j;
        //boundry conditions
        if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1){
            dfs(grid,ni,nj,n,m);
        }
      }
   }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //first row 
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                dfs(grid,0,i,n,m);
            }
        }
        //last col 
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1){
                dfs(grid,i,m-1,n,m);
            }
        }
        //last row 
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==1){
                dfs(grid,n-1,i,n,m);
            }
        }
        //first col
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(grid,i,0,n,m);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};