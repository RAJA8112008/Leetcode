class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word=strs[0];
        string ans="";
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            //find in other words i th char 
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