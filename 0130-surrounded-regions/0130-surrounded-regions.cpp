class Solution {
public:
vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(vector<vector<char>>& board,int i,int j,int n,int m){
   board[i][j]='Y';
   //nbr 
   for(auto dir:directions){
    int ni=dir.first+i;
    int nj=dir.second+j;
    //boundry conditions 
    if(ni>=0 && nj>=0 && ni<n && nj<m && board[ni][nj]=='O'){
        dfs(board,ni,nj,n,m);
    }
   }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        // first row
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                 dfs(board,0,i,n,m);
            }
        }
        //last col
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(board,i,m-1,n,m);
            }
        }
        //last row 
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                dfs(board,n-1,i,n,m);
            }
        }
        //first col 
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='Y'){
                    board[i][j]='O';
                }
            }
        }
    }
};