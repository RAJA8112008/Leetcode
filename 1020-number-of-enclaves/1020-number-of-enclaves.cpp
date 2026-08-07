class Solution {
public:
vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
    grid[i][j]=0;
    //directions 
    for(auto dir:directions){
        int ni=i+dir.first;
        int nj=j+dir.second;
        //if it is in boundry
        if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
            dfs(grid,ni,nj,m,n);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
       int m = grid.size();
      int n = grid[0].size();

// Top row
     for (int j = 0; j < n; j++) {
        if (grid[0][j] == 1)
        dfs(grid, 0, j, m, n);
      }

// Bottom row
       for (int j = 0; j < n; j++) {
         if (grid[m - 1][j] == 1)
        dfs(grid, m - 1, j, m, n);
        }

// Left column
      for (int i = 0; i < m; i++) {
         if (grid[i][0] == 1)
        dfs(grid, i, 0, m, n);
      }

// Right column
    for (int i = 0; i < m; i++) {
         if (grid[i][n - 1] == 1)
        dfs(grid, i, n - 1, m, n);
      }
        //check 
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};