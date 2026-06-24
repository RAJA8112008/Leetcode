class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //first store indexes having zero 
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>rowstore;
        vector<int>colstore;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rowstore.push_back(i);
                    colstore.push_back(j);
                }
            }
        }
       //convert row having zero its all elements 
       for(auto row:rowstore){
        for(int i=0;i<m;i++){
            matrix[row][i]=0;
        }
       }

        for(auto col:colstore){
        for(int i=0;i<n;i++){
            matrix[i][col]=0;
        }
       }
       
    }
};