class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int m=nums1.size();
        int n=nums2.size();
        vector<int>ans;
        ans.reserve(m + n);
        int  i=0,j=0,k=0;
        while(i<m && j<n){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                ans.push_back(nums2[j]);
                i++;
                j++;
            }else if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        //copy all the remaining values
        while(i<m ){
            ans.push_back(nums1[i]);
            i++;
        }
         while(j<n ){
            ans.push_back(nums2[j]);
            j++;
        }
        //median process
      int size=ans.size();
     int s=0;
     int e=size-1;
    
     int mid=s+(e-s)/2;
       if(size%2==0){
           return (ans[mid]+ans[mid+1])/2.0;
       }else{
           return ans[mid];
       }  
    }
};
