class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while(s.length()<t.length() && i<s.length() && j<t.length()){
            while(j<t.length()){
               if(s[i]!=t[j]){
                j++;
               }else{
                 t[j] = '#';
                i++;
               }
            }
        }
        if(i==s.length()){
            return true;
        }
        return false;
    }
};