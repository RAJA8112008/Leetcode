class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;//nums1
        int j=0;//nums2
        while(i>=0 && j<n){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
                i--;
                j++;
            }else{
                break;
            }
        }
             sort(nums1.begin(), nums1.begin() + m);
             sort(nums2.begin(), nums2.end());

        // Put nums2 elements in remaining positions of nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};