class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int row=matrix.size();
       int col=matrix[0].size();
       int firstrow=0;
       int firstcol=0;
       int lastrow=row-1;
       int lastcol=col-1;
       int count=0;
       int total=row*col;
       vector<int>ans;
       while(count<total){
        //first row 
        for(int i=firstcol;i<=lastcol && count<total;i++){
            ans.push_back(matrix[firstrow][i]);
            count++;
        }
        firstrow++;
        //last col 
        for(int i=firstrow;i<=lastrow && count<total;i++){
            ans.push_back(matrix[i][lastcol]);
            count++;
        }
        lastcol--;
        //last row 
        for(int i=lastcol;i>=firstcol && count<total;i--){
            ans.push_back(matrix[lastrow][i]);
            count++;
        }
        lastrow--;
        //first row 
        for(int i=lastrow;i>=firstrow && count<total;i--){
            ans.push_back(matrix[i][firstcol]);
            count++;
        }
        firstcol++;
       }
       return ans;
    }
};