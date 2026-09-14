class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp=strs[0];
        string ans="";
        for(int i=0;i<temp.size();i++){
            char ch=temp[i];
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=ch){
                    return ans;
                }
            }
            ans+=ch;
        }
        return ans;
    }
};