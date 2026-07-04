class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s.length()!=goal.length())return false;
       string ans=s+s;
       //find goal in ans 
       return ans.find(goal)!=string::npos;
    }
};