class Solution {
public:

void dfs(unordered_map<int,vector<int>>&adj,int node,vector<bool>&visited){
    //mark it visited 
   visited[node]=true;
    
     for(auto nbr:adj[node]){
        //check boundry conditions 
        if(!visited[nbr]){
            dfs(adj,nbr,visited);
        }
     }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        int island=0;
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n,false);
         for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                island++;
            }
         }
        return island;
    }
};