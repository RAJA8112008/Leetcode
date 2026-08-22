class Solution {
public:
 void dfs(int node,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
    //mark as visited
    visited[node]=true;
    //travese on its nbr 
    for(auto nbr:adj[node]){
        if(!visited[nbr]){
            dfs(nbr,visited,adj);
        }
    }
 }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //usind DFS 

          //if edges are not enought to connect graph 
          if(connections.size()<n-1)return -1;
        //create an adj list 

        unordered_map<int,vector<int>>adj;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            //undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
      
        int components=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                components++;
            }
        }
        return components-1;
    }
};