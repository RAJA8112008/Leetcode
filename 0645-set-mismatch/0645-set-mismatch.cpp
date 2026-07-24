class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //store freq
        vector<int>ans;
        int n=nums.size();
        vector<int>freq(n+1,0);
        for(auto x:nums){
            freq[x]++;
        }
        int dup=-1;
        int miss=-1;
        //travese on freq array 
        for(int i=1;i<=n;i++){
            //store duplicate number 
            if(freq[i]==2){
                dup = i;
            }
             //store missing number
            if(freq[i]==0){
              miss=i;
            }
        }
      return {dup,miss};
    }
};