class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i=0;i<m;i++){
            if(i==0){
                string temp="";
                for(int j=0;j<n;j++){
                    temp+='.';
                }
                ans.push_back(temp);
            }else{
                 string temp="";
                 for(int j=0;j<n-1;j++){
                    temp+='#';
                }
                temp+='.';
                ans.push_back(temp);
            }
        }
        return ans;
    }
};