class Solution {
public:
vector<pair<int,int>>directions={{-1,0},{0,-1},{1,0},{0,1}};
 void  dfs(vector<vector<char>>& grid,int i,int j,int n,int m){
    grid[i][j]='0';
  //check directions 
  for(auto dir:directions){
      int ni=dir.first + i;
      int nj=dir.second+j;
      //check boundry 
      if(ni>=0 && nj>=0 &&  ni<n && nj<m && grid[ni][nj]=='1'){
        dfs(grid,ni,nj,n,m);
      }
  }

 }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //DFS 
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    //dfs
                    dfs(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};