class Solution {
public:
vector<pair<int,int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        //dijkastra algo 
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<bool>>visited(n,vector<bool>(m,false));
       vector<vector<int>>path(n,vector<int>(m,INT_MAX));
       priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
       pq.push({grid[0][0],0,0});
       path[0][0]=grid[0][0];
       visited[0][0]=true;
       while(!pq.empty()){
         auto [time,i,j]=pq.top();
         pq.pop();
         if(i==n-1 && j==m-1)return time;
         //move its nbr 
         for(auto dir:directions){
            int ni=i+dir.first;
            int nj=j+dir.second;
        
            //boundry conditions 
            if(ni>=0 && nj>=0 && ni<n &&  nj<m && !visited[ni][nj]){
                //update 
                int newtime=max(time,grid[ni][nj]);
                if(newtime<path[ni][nj]){
                    path[ni][nj]=newtime;
                    pq.push({newtime,ni,nj});
                    visited[ni][nj]=true;
                }
            }
         }

       }
       return -1;
      
    }
};