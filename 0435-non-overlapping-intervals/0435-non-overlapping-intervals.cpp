class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int count=0;
        ans.push_back(intervals[0]);
       for(int i=1;i<n;i++){
            //overlapp condition
            if(ans.back()[1]>intervals[i][0]){
                 //remove chose 
                 if(ans.back()[1]>=intervals[i][1]){
                    count++;
                    ans.push_back(intervals[i]);
                 }else{
                    count++;
                 }
            }else{
                ans.push_back(intervals[i]);
            }
       }
        return count;
    }
};