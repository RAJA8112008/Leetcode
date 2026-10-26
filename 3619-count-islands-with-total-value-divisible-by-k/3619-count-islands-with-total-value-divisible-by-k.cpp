class Solution {
public:
vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int i,int j,vector<vector<int>>& grid,int n,int m,long long& sum){
     sum+=grid[i][j];
     grid[i][j]=-1;
    //check diretions 
    for(auto dir :directions){
        int ni=i+dir.first;
        int nj=j+dir.second;
        //check boundry conditiond 
        if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]!=0 && grid[ni][nj]!=-1){
            dfs(ni,nj,grid,n,m,sum);
        }
    }
}

    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
             long long sum=0;
                if(grid[i][j]!=0 && grid[i][j]!=-1){
                     dfs(i,j,grid,n,m,sum);
                   if(sum%k==0){
                     count++;
                   }
                }
            }
        }
        return count;
    }
};