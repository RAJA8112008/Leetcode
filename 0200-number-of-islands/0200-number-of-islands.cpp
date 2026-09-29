class Solution {
public:
vector<pair<int,int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
void dfs(vector<vector<char>>& grid,int i,int j,int n,int m){
    //mark it visited 
    grid[i][j]='0';
    //traverse on its  all directions 
     for(auto dir:directions){
        int ni=dir.first+i;
        int nj=dir.second+j;
        //check boundry conditions 
        if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]=='1'){
            dfs(grid,ni,nj,n,m);
        }
     }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,n,m);
                    island++;
                }
            }
        }
        return island;
    }
};