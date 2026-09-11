class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int st=0;
        int ed=n-1;
        while(st<=ed){
            int mid=st+(ed-st)/2;
            if(nums[mid]==target){
                 return true;
            }
             else if (nums[mid] == nums[st] && nums[mid] == nums[ed]) {
                st++;
                ed--;
            }else  if(nums[mid]>=nums[st]){
                //CHECK target is exits or not 
                if(target>=nums[st] && target<=nums[mid]){
                    ed=mid-1;
                }else{
                    st=mid+1;
                }
            }
            else{
                //check it is exits or not 
                if(target>=nums[mid] && nums[ed]>=target){
                    st=mid+1;
                }else{
                    ed=mid-1;
                }
            }
        }
        return false;
    }
};