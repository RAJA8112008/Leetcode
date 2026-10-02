class Solution {
public:
vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        q.push({0,0,0});
        dist[0][0]=0;
        while(!q.empty()){
            auto temp=q.top();
            q.pop();
            int effort=get<0>(temp);
            int i=get<1>(temp);
            int j=get<2>(temp);
            if(i==n-1 && j==m-1)return effort;
            //directions
            for(auto dir:directions){
                int ni=dir.first+i;
                int nj=dir.second+j;
                //boundry conditions 
                if(ni>=0 && nj>=0 && ni<n && nj<m && dist[ni][nj]){
                    //difference 
                    int diff=abs(heights[ni][nj]-heights[i][j]);
                    int neweffort=max(effort,diff);
                    if(neweffort<dist[ni][nj]){
                        q.push({neweffort,ni,nj});
                        dist[ni][nj]=neweffort;
                    }
                    
                }
            }
        }
        return 0;
    }
};