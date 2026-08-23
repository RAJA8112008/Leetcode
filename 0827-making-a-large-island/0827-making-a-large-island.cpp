class Solution {
public:
vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int i,int j,int m,int n,int id,vector<vector<int>>& grid,vector<vector<bool>>&visited,int&count){
    //mark is visited
    visited[i][j]=true;
    grid[i][j]=id;
    count++;
    //move its directions 
    for(auto dir:directions){
                int ni=i+dir.first;
                int nj=j+dir.second;
                //boundry condittions 
                if(ni>=0 && nj>=0 &&  ni<m && nj<n && grid[ni][nj]==1 && !visited[ni][nj]){
                     dfs(ni,nj,m,n,id,grid,visited,count);
                      
                }
    }
}
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int area=0;
         unordered_map<int,int>store;
          vector<vector<bool>>visited(m,vector<bool>(n,false));
        //visited vector
        int id=2;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    //move its directions 
                       int count=0;
                     dfs(i,j,m,n,id,grid,visited,count);
                     //store count && id 
                        store[id]=count;
                       id++;
                   }
            }
        }
        //again dfs 
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                //again directions
                set<int>val;
                for(auto dir:directions){
                    int ni=i+dir.first;
                    int nj=j+dir.second;
                    //boundries
                    if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]!=0){
                        val.insert(grid[ni][nj]);
                    }
                }
              int currarea=1;
              for(auto v:val){
                currarea+=store[v];
              }
              area=max(area,currarea);
            }
          }
        }
        if(area==0){
            return m*n;
        }
        return area;
    }
};