class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //if DAG->cycle is present in the Graph then it is not 
        int totalnode=0;
        //Store In Degree 
        vector<int>InDegree(numCourses,0);
        //craete an AdjList 
        unordered_map<int,vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            //directed graph
            adj[u].push_back(v);
            //store Indegree
            InDegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<InDegree.size();i++){
            if(InDegree[i]==0){
                q.push(i);
            }
        }
        //pop from the queue
        while(!q.empty()){
            int node=q.front();
             totalnode++;
            q.pop();
            //and traverse its nbr to remove the inDegree
            for(auto nbr:adj[node]){
                //reduce the Indegree 
                InDegree[nbr]--;
                //push nbr if its inDegree in ZERO 
                if(InDegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
       if(totalnode==numCourses){
        return true;
       }
       return false;
    }
};