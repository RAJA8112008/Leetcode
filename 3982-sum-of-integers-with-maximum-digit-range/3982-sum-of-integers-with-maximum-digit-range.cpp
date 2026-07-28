class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        //find max 
        int n=nums.size();
        if(n==1)return nums[0];
        //with there indexes 
        sort(nums.begin(),nums.end());
        vector<int>new_maxi(n);
        vector<int>new_mini(n);
        vector<pair<int,int>>diff(n);
        for(int i=0;i<n;i++){
              //gett as a string 
           string s=to_string(nums[i]);
          char maxi=*max_element(s.begin(),s.end());//7
           char mini=*min_element(s.begin(),s.end());//5
           //again convert into int 
            //push in max in min vector
            int mx=maxi-'0';
            int mn=mini-'0';
                new_maxi[i]=mx;
                new_mini[i]=mn;
                diff[i]={mx-mn,i};
                
        }
        //travese on diff vector and return sun
       //return sum whose diff is rqual 
     sort(diff.begin(), diff.end());
      int maxDiff = diff.back().first;
        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (diff[i].first == maxDiff)
                ans += nums[diff[i].second];
            else
                break;
        }

        return ans;
    }
};