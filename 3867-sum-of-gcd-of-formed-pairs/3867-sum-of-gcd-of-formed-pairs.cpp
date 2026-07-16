class Solution {
public:
long long gcd(int a,int b){
    while(b!=0){
        long long rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
    long long gcdSum(vector<int>& nums) {
        //create prefixgcd and mxi
        vector<int>prefixgcd;
        int mxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mxi=max(mxi,nums[i]);
            prefixgcd.push_back(gcd(mxi,nums[i]));
        }
        //sort prefixgcd 
        sort(prefixgcd.begin(),prefixgcd.end());
         int n=prefixgcd.size();
        //two pointer 
        int s=0;
        int ed=n-1;
        long long result=0;
        while(s<ed){
            result+=gcd(prefixgcd[s],prefixgcd[ed]);
            s++;
            ed--;
        }
      return result;
    }
};