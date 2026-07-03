class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth=0;
        string ans="";
        for(auto val:s){
            if(val=='('){
                //ignore first parenthese
                if(depth>0){
                    ans+=val;
                }
                depth++;
            }else{
                depth--;
                if(depth>0){
                    ans+=val;
                }
            }
        }
         return ans;
    }
};