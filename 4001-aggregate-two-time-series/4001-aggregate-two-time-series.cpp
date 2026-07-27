class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
       
            vector<vector<int>>ans;
        //two pointer 
        int i=0;
        int j=0;
        sort(series1.begin(),series1.end());
        sort(series2.begin(),series2.end());
        while(i<series1.size() && j<series2.size()){
            if(series1[i][0]==series2[j][0]){
             ans.push_back({series1[i][0],series1[i][1]+series2[j][1]});
                i++;
                j++;
            }else if(series1[i][0]<series2[j][0]){
                ans.push_back({series1[i][0],series1[i][1]+series2[j][1]});
                i++;
            }else{
                 ans.push_back({series2[j][0],series2[j][1]+series1[i][1]});
                j++;
            }
        }
        //copy remaining 
        while(i<series1.size()){
            ans.push_back({series1[i][0],series1[i][1]});
            i++;
        }
         while(j<series2.size()){
            ans.push_back({series2[j][0],series2[j][1]});
            j++;
        }
        return ans;
    }
};