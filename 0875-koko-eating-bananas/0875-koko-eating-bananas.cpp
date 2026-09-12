class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1;
        int ed=*max_element(piles.begin(), piles.end());
        long long ans=-1;
        while(st<=ed){
            int mid=st+(ed-st)/2;
           long long newh=0;
            for(auto val:piles){
             newh += ceil((double)val/mid);
            }
            if(newh<=h){
                ans=mid;
                ed=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};