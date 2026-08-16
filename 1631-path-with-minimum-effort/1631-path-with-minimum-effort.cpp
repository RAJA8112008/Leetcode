class Solution {
public:
vector<pair<int,int>>directions{
     {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
    int minimumEffortPath(vector<vector<int>>& heights) {
        //Dijkastra algorithum 
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
     priority_queue<
    pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>
     > q;
       
        q.push({0,{0,0}});
        result[0][0]=0;
        while(!q.empty()){
            int wt=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();
            //nbr 
             if(wt > result[i][j]) continue;
            if(i==m-1 && j==n-1)return wt;
            for(auto dir:directions){
                int ni = i + dir.first;
                int nj = j + dir.second;
                //boundry condition 
                 if(ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;
              int edgewt=abs(heights[ni][nj]-heights[i][j]);
              int newEffort = max(wt, edgewt);

                if(newEffort < result[ni][nj]) {

                    result[ni][nj] = newEffort;

                    q.push({newEffort,{ni,nj}});
                }
            }
        }

       return 0;

    }
};