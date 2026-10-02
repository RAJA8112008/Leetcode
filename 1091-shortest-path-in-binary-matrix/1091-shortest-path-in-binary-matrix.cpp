class Solution {
public:
vector<pair<int,int>> directions = {
    {1,0}, {0,1}, {-1,0}, {0,-1},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
           if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        q.push({0,0,0});
        visited[0][0]=true;
        while(!q.empty()){
            auto temp=q.top();
            q.pop();
           int level = get<0>(temp);
           int i     = get<1>(temp);
           int j     = get<2>(temp);

            if(i==n-1 && j==m-1)return level+1;
            //new directions 
            for(auto dir:directions){
                int ni=dir.first+i;
                int nj=dir.second+j;
                //boundery conditions 
                if(ni>=0 && nj>=0 &&  ni<n && nj<m && grid[ni][nj]==0 && !visited[ni][nj]){
                    q.push({level+1,ni,nj});
                    visited[ni][nj]=true;
                }
            }
        }
     return -1;
    }
};