class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;
         pascal.push_back({1});
       for(int i=1;i<numRows;i++){
        vector<int>prev=pascal.back();
        vector<int>newrow;
            newrow.push_back({1});
            for(int i=0;i<prev.size()-1;i++){
                newrow.push_back({prev[i]+prev[i+1]});
            }
            newrow.push_back({1});
            pascal.push_back(newrow);
       }
       return  pascal;
    }
};