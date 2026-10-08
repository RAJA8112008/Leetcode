class Solution {
public:
 const long long MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        //creatte an adjList 
        unordered_map<int,vector<pair<int,long long>>>adj;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            long long t=roads[i][2];
            //undired graph 
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        //shortet amount of time 
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>count(n,0);
        count[0]=1;
        dist[0]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long ,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            int u=pq.top().second;
            long long time=pq.top().first;
            pq.pop();
            if (time > dist[u])
               continue;
            //nbr 
            for(auto nbr:adj[u]){
                int v=nbr.first;
              long long ntime=nbr.second;
                //update 
              if(ntime+time<dist[v]){
                dist[v]=ntime+time;
                //insert into queue 
                pq.push({ntime+time,v});
                count[v]=count[u];
              }else if(ntime+time==dist[v]){
                //update count
                count[v]=(count[u]+count[v])%MOD;
              }
            }
        }
         return count[n-1];
    }
};