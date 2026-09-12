class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int st=1;
        int ans=0;
        int ed=*max_element(nums.begin(),nums.end());
        while(st<=ed){
            int mid=st+(ed-st)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil((double)nums[i]/mid);
            }
            if(sum<=threshold){
               ans=mid;
              ed=mid-1;
            }else{
                st=mid+1;
            }

        }
        return ans;
    }
};