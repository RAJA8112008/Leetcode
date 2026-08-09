class Solution {
public:
  bool dfs(vector<vector<int>>&graph,int node,vector<int>&color,int currcolor){
    //make node colored
    color[node]=currcolor;
    //adj 
    for(auto v:graph[node]){
        //already color 
        if(color[v]==currcolor)return false;

        if(color[v]==-1){
            if(!dfs(graph,v,color,1-currcolor))return false;
        }
    }
return true;
  }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int currcolor=1;
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
             if(color[i] == -1) {
                if(!dfs(graph, i, color, currcolor))
                    return false;
            }
        }
        return true;
    }
};