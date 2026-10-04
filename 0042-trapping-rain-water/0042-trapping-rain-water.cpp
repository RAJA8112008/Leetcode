class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        st.push(height[0]);
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(height[i],st.top());
             st.push(max(st.top(),height[i]));
        }
        //empty stack 
        while(!st.empty()){
            st.pop();
        }
        right[n-1]=height[n-1];
        st.push(height[n-1]);
        for(int i=n-2;i>=0;i--){
            right[i]=max(st.top(),height[i]);
            st.push(max(st.top(),height[i]));
        }
          //traves 
      int water=0;
      for(int i=0;i<n;i++){
        int mini=min(left[i],right[i]);
          water+= mini-height[i];
      }
      return water;
    }
};