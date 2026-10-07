class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>storeIdx;
        sort(intervals.begin(),intervals.end());
       priority_queue<int,vector<int>,greater<int>>q;
       q.push(intervals[0][1]);
        for(int i=1;i<intervals.size();i++){
           if(q.top()<intervals[i][0]){
              q.pop();
              q.push(intervals[i][1]);
           }else{
            q.push(intervals[i][1]);
           }
        }
        return q.size();
    }
};