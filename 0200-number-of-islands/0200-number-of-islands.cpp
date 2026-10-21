class Solution {
public:
    vector<pair<int,int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int i,int j,vector<vector<char>>& grid,int n,int m){
        //mark visited 
        grid[i][j]='2';
        for(auto dir:directions){
            int ni=dir.first+i;
            int nj=dir.second+j;
            //conditions out of bound 
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]=='1' ){
                dfs(ni,nj,grid,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};