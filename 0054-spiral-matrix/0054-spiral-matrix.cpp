class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int total =row*col;
        int strow=0;
        int edrow=row-1;
        int stcol=0;
        int edcol=col-1;
        int count=0;//to track the number of elem are visited
      vector<int>ans;
      while(count<total){
        //first col 
        for(int i=stcol;i<=edcol && count<total;i++){
            ans.push_back(matrix[strow][i]);
            count++;
        }
        strow++;
        //last col 
        for(int i=strow;i<=edrow && count<total;i++){
            ans.push_back(matrix[i][edcol]);
            count++;
        }
        edcol--;
        //last col
        for(int i=edcol;i>=stcol && count<total;i--){
            ans.push_back(matrix[edrow][i]);
            count++;
        }
        edrow--;
        //first col 
        for(int i=edrow;i>=strow && count<total;i--){
            ans.push_back(matrix[i][stcol]);
            count++;
        }
        stcol++;
      }
    return ans;

    }
};