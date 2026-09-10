class Solution {
public:
void upperbound(vector<int>&nums,int target,int& first){
    int n=nums.size();
    int st=0;
    int ed=n-1;
    while(st<=ed){
        int mid=st+(ed-st)/2;
        if(nums[mid]<=target){
            if(nums[mid]==target){
                first=mid;
            }
            
           st=mid+1;
        }else{
            ed=mid-1;
        }
    }
}
//secoind occurence 
void lowerbound(vector<int>&nums,int target,int& second){
    int n=nums.size();
    int st=0;
    int ed=n-1;
    while(st<=ed){
        int mid=st+(ed-st)/2;
        if(nums[mid]>=target){
            if(nums[mid]==target){
                second=mid;
            }
            
            ed=mid-1;
        }else{
             st=mid+1;
        }
    }
}
    vector<int> searchRange(vector<int>& nums, int target) {
        //first find lower bound 
        int first=-1;
        int second=-1;
        lowerbound(nums,target,first);
        upperbound(nums,target,second);
        return {first,second};
    }
};