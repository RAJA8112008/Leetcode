class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          int n=heights.size();
          vector<int>left(n);
          vector<int>right(n);
          stack<int>st;
         //left 
         for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i]=st.empty()?-1:st.top();
            st.push(i);
         }
         //stack empty 
         while(!st.empty()){
            st.pop();
         }
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i]=st.empty()?n:st.top();
            st.push(i);
         }
         int maxarea=0;
         for(int i=0;i<n;i++){
            int area=(right[i]-left[i]-1)*heights[i];
            maxarea=max(maxarea,area);
         }
        return maxarea;
    }
};