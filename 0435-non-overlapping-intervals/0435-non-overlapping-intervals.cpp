class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int i=0;
        int j=1;
        int count=0;
        while(j<n){
            //overlapp
            if(intervals[i][1]>intervals[j][0]){
                if(intervals[i][1]<intervals[j][1]){
                        count++;
                        j++;
                }else{
                    count++;
                    i=j;
                    j++;
                }
            }else{
                 i=j;
                j++;
            }
           
        }
        return count;
    }
};