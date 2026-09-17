class Solution {
public:
    int nearestDrone(vector<vector<int>>& nums, vector<int>& target) {
        int n=nums.size();
         int minval=INT_MAX;
        int ans=-1;
        //it will run for the rowa
        for(int i=0;i<n;i++){
            //it will run rows elem
                int x_cordinate=nums[i][0];
                int y_cordinate=nums[i][1];
                int range=nums[i][2];
               int sum=abs(x_cordinate-target[0])+abs(y_cordinate-target[1]);
               if(sum<=range){
                 if(sum<minval){
                     minval=sum;
                     ans=i;
                 }
            }
        }
        return ans;
    }
};