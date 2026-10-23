class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxwater=INT_MIN;
        while(i<=j){
            int width=j-i;
            maxwater=max(maxwater,width* min(height[i],height[j]));
            if(height[i]==height[j]){
                maxwater=max(maxwater,width*height[i]);
                i++;
                j--;
            }else if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
            
        }
        return maxwater;
    }
};