class Solution {
public:
int find(int&x,vector<int>&parent){
    //if parent have same then return the parent node
    if(parent[x]==x)return parent[x];
    return find(parent[x],parent);
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        //if edges are sufficent 
        if(connections.size()<n-1)return -1;
        //Union find method 
        vector<int>element(n);
        for(int i=0;i<n;i++){
            element[i]=i;
        }
        //parents 
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        // connents components 
        int components=n;
        for(int i=0;i<connections.size();i++){
            int x_parent=find(connections[i][0],parent);
            int y_parent=find(connections[i][1],parent);
            //check both are same or not 
            if(x_parent!=y_parent){
                 parent[x_parent]=y_parent;
                components--;
            }
        }
        return components-1;
    }
};