class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        //first  store row 
        vector<int>row;
        //store column
        vector<int>col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        //now convert the all rows into zero 
        for(int i=0;i<row.size();i++){
            int nrow=row[i];
            //convert with zero 
            for(int i=0;i<n;i++){
                matrix[nrow][i]=0;
            }
        }
         //now convert the all column into zero
         for(int i=0;i<col.size();i++){
            int ncol=col[i];
            //convert with zero 
            for(int i=0;i<m;i++){
                matrix[i][ncol]=0;
            }
        }
        
    }
};