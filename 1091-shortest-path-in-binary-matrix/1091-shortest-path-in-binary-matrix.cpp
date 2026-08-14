class Solution {
public:
vector<pair<int,int>> directions = {
    {1,0},    
    {0,1}, 
    {-1,0},  
    {0,-1}, 
    {-1,-1},
    {-1,1},  
    {1,-1}, 
    {1,1}     
};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0)return -1;
      queue<pair<pair<int,int>, int>> q;
        //BFS 
       q.push({{0,0},1});
       grid[0][0]=1;
       while(!q.empty()){
        int i=q.front().first.first;
        int j=q.front().first.second;
        int dist=q.front().second;
        q.pop();
        if(i==n-1 && j==m-1)return dist;
        //travese on directions 
        for(auto dir:directions){
            int ni=dir.first+i;
            int nj=dir.second+j;
            //check boundry conditions 
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==0){
                grid[ni][nj]=1;
                q.push({{ni,nj},dist+1});
            }
        }
       }
   return -1;
    }
};