class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        //create two vectors 
          vector<int>arr1;
        arr1.push_back(nums[0]);
        vector<int>arr2;
        arr2.push_back(nums[1]);
        //push single single elm in arrs
        //travesre on nums 
        for(int i=2;i<=nums.size()-1;i++){
            //check element with high val 
            int val= nums[i];
           
            int a1_val=arr1.back();
            
            int a2_val=arr2.back();
           
            //check which is greater 
            if(a1_val<a2_val){
                arr2.push_back(val);
            }else{
                arr1.push_back(val);
            }
        }
        // //copy all elements in same 
        int i=0;
        int j=0;
        vector<int>result;
        //copy remaing value 
        while(i<arr1.size()){
             result.push_back(arr1[i]);
                i++;
        }
         while(j<arr2.size()){
             result.push_back(arr2[j]);
                j++;
        }
        
        return result;
    }
};