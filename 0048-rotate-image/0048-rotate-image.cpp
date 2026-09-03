class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        //create a matrix
        vector<vector<int>>mat(row,vector<int>(col,0));
        //step 1:interchange row to column 
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mat[j][i]=matrix[i][j];
            }
        }
        //step 2:reverse last col to first column
       for(int i=0;i<row;i++){
        reverse(mat[i].begin(),mat[i].end());
       }
        matrix=mat;
    }
};