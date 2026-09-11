class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st=0;
        int ed=nums.size()-1;
        while(st<ed){
            int mid=st+(ed-st)/2;
            if(mid %2==1)mid--; //becoue each val is in twice so make sure it is even
            if(nums[mid]==nums[mid+1]){
                st=mid+2;
            }else{
                ed=mid;
            }
        }
        return nums[ed];
    }
};