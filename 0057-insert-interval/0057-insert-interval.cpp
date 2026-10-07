class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        vector<vector<int>>temp;
        for(int i=0;i<intervals.size();i++){
            temp.push_back(intervals[i]);
        }
       
            temp.push_back(newInterval);
        
         
        sort(temp.begin(),temp.end());
         ans.push_back(temp[0]);
      for(int i=1;i<temp.size();i++){
          //check overlap 
          if(ans.back()[1]>=temp[i][0]){
            ans.back()[1]=max(ans.back()[1],temp[i][1]);
          }else{
            ans.push_back(temp[i]);
          }
      }
     return ans;
    }
};