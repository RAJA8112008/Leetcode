class Solution {
public:
int firstOccurence(vector<int>&nums,int target){
    int st=0;
    int ed=nums.size()-1;
    int ans1=-1;
    while(st<=ed){
        int mid=st+(ed-st)/2;
        if(nums[mid]==target){
            ans1=mid;
            ed=mid-1;
        }else if(nums[mid]<target){
            st=mid+1;
        }else{
            ed=mid-1;
        }
    }
    return ans1;
}

int secondOccurence(vector<int>&nums,int target){
    int st=0;
    int ed=nums.size()-1;
    int ans2=-1;
    while(st<=ed){
        int mid=st+(ed-st)/2;
        if(nums[mid]==target){
            ans2=mid;
           st=mid+1;
        }else if(nums[mid]<target){
            st=mid+1;
        }else{
            ed=mid-1;
        }
    }
    return ans2;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOccurence(nums,target);
        int second=secondOccurence(nums,target);
        return {first,second};
    }
};