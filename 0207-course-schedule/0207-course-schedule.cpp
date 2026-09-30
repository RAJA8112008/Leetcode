class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      unordered_map<int,vector<int>>adj;
      int n=prerequisites.size();
      if(n==1)return true;
      if(n==0)return true;
      long long course=0;
      vector<int>inorder(numCourses,0);
      for(int i=0;i<n;i++){
          int u=prerequisites[i][0];
          int v=prerequisites[i][1];
           adj[v].push_back(u);
           inorder[u]++;
      }
       queue<int>q;
       for(int i=0;i<numCourses;i++){
        if(inorder[i]==0){
            q.push(i);
        }
       }
       while(!q.empty()){
        int node=q.front();
        q.pop();
        course++;
        for(auto nbr:adj[node]){
            inorder[nbr]--;
            if(inorder[nbr]==0){
                q.push(nbr);
            }
        }
       }
       return numCourses==course;
    }
};