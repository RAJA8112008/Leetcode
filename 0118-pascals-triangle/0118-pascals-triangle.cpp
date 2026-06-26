class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>rows;
        rows.push_back({1});
         for(int i=1;i<numRows;i++){
            //store n-1 row to create n row 
            vector<int>lastrow=rows.back();
            vector<int>currrow;
             currrow.push_back(1);
            for(int i=0;i<lastrow.size()-1;i++){
            currrow.push_back({lastrow[i]+lastrow[i+1]});
            }
            currrow.push_back(1);
            rows.push_back({currrow});
         }
    return rows;
    }
};