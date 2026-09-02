class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       //brute force 
       int n=nums.size();
       vector<int>neg;
       vector<int>pos;
       for(int i=0;i<n;i++){
        if(nums[i]>=0){
            pos.push_back(nums[i]);
        }else{
            neg.push_back(nums[i]);
        }
       } 
       vector<int>ans;
       int i=0;
       int j=0;
       while(i<neg.size() || j<pos.size()){
           if(pos[j]){
            ans.push_back(pos[j]);
            j++;
           }
           if(neg[i]){
            ans.push_back(neg[i]);
            i++;
           }
       }
       return ans;
    }
};