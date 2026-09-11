class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        int st=0;
        int ed=n-1;
        while(st<ed){
            int mid=st+(ed-st)/2;
            if(nums[mid]<nums[mid+1]){
               st=mid+1;
            }else{
                ed=mid;
            }
        }
        return ed;
    }
};