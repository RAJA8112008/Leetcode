class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;

        for(int i=0;i<nums1.size();i++){
             stack<int>st;
              int num=nums1[i];
             for(int i=nums2.size()-1;i>=0;i--){
                st.push(nums2[i]);
              }
            while(!st.empty() && num!=st.top()){
                st.pop();
            }
            // if(!st.empty()){
            //     st.pop();
            // }
            
            while(!st.empty() && num>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                ans.push_back(st.top());
            }else{
                ans.push_back(-1);
            }

        }
        return ans;
    }
};