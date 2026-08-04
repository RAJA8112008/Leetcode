class Solution {
public:
vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(vector<vector<int>>&image,
vector<vector<bool>>&visited,int oldcolor,int newcolor,int n,int m,int i,int j){

    if(i>=0 && i<n && j>=0 && j<m && image[i][j]==oldcolor){
        if(visited[i][j]!=true){
            image[i][j]=newcolor;
             visited[i][j]=true;
               //find directions 
        for(auto dir:directions){
            int ni=dir.first+i;
            int nj=dir.second+j;
            //dfs call 
                 dfs(image,visited,oldcolor,newcolor,n,m,ni,nj);
        }
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n=image.size();
    int m=image[0].size();
    int oldcolor=image[sr][sc];
     vector<vector<bool>> visited(n, vector<bool>(m, false));
    dfs(image,visited,oldcolor,color,n,m,sr,sc);
    return image;
    }
};