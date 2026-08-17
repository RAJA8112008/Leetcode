class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create an adj list 
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            //directed map
            adj[u].push_back({v,w});
        }
        //crete a vector which will store min to reach each node 
        vector<int>dist(n+1,INT_MAX);
        //create an priority queue 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

        //push into the queue 
        q.push({k,0});
        dist[k]=0;
        while(!q.empty()){
            int node=q.top().first;
            int d=q.top().second;
            q.pop();
            //traverse on its nbr with min d
            for(auto nbr:adj[node]){
                int n_node=nbr.first;
                int n_d=nbr.second;
                if(d+n_d<dist[n_node]){
                    dist[n_node]=d+n_d;
                    q.push({n_node,d+n_d});
                }
            }

        }
        //
       int maxi=0;
       for(int i=1;i<=n;i++){
        if(dist[i]==INT_MAX)return -1;
        maxi=max(maxi,dist[i]);
       }
       return maxi;
    }
};