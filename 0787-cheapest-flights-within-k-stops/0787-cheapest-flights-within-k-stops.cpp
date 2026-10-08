class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //create an adjList 
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int cost=flights[i][2];
            //directed graph 
            adj[u].push_back({v,cost});
        }
        queue<tuple<int,int,int>>q;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({src,0,-1});
        while(!q.empty()){
          int u=get<0>(q.front());
          int cost=get<1>(q.front());
          int stop=get<2>(q.front());
         
          q.pop();
          //traverse its nbr 
          for(auto nbr:adj[u]){
            int v=nbr.first;
            int nbrcost=nbr.second;
            //will update if stop is less then k stops 
            if(nbrcost+cost<dist[v] && stop<=k-1){
                dist[v]=nbrcost+cost;
                q.push({v,nbrcost+cost,stop+1});
            }
          }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};