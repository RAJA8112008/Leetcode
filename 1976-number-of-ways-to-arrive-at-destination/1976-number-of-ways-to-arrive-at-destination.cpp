class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //craeet an adjList 
        unordered_map<int,vector<pair<int,int>>>adj;
        //traverse on roads 
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            //undirecter graph 
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        //create an priorrtiy queue 
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
       const long long MOD = 1e9 + 7;
        //create an freq count arry 
        vector<long long>freq(n,LLONG_MAX);
        //create an array to store count 
        vector<long long>count(n,0);
        //push into the queue  and update the count 
        pq.push({0,0});
        //update the count 
        freq[0]=0;
        count[0]=1;
        while(!pq.empty()){
           auto temp=pq.top();
           long long dist=temp.first;
           int node=temp.second;
           pq.pop();
           //traverse on its nbr nodes 
           for(auto nbr:adj[node]){
            int n_node=nbr.first;
            int n_dist=nbr.second;
            //check curr dist is smaller then 
           if (dist + n_dist < freq[n_node]) {
              freq[n_node] = dist + n_dist;
               pq.push({dist + n_dist, n_node});
               count[n_node] = count[node];
             }else if (dist + n_dist == freq[n_node]) {
              count[n_node] =
               (count[n_node] + count[node]) % MOD;
            }
           }
        }
        return count[n-1];
    }
};