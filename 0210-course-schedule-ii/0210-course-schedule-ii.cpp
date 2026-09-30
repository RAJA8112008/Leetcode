class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int n=prerequisites.size();
    vector<int>Inorder(numCourses,0);
    //create adj List 
    vector<int>ans;
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<n;i++){
        int u=prerequisites[i][0];
        int v=prerequisites[i][1];
        adj[v].push_back(u);
        Inorder[u]++;
    }
    queue<int>q;
    //remove value who have inorder zero 
    for(int i=0;i<numCourses;i++){
        if(Inorder[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
       //move its neb and reduce the inorder 
        for(auto nbr:adj[node]){
            Inorder[nbr]--;
            if(Inorder[nbr]==0){
                q.push(nbr);
            }
        }
    }
    if(ans.size()!=numCourses)return {};
    return ans;
    }
};