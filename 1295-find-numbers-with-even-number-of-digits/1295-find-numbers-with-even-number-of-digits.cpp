class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int count=0;
       
        for(int i=0;i<n;i++){
             int digitcount=0;
            int num=nums[i];

             while(num!=0){
                int digit=num%10;
            
                     digitcount++;
                
               
                num=num/10;
             }
             if(digitcount %2 ==0){
                count++;
             }
        }
        return count;
    }
};