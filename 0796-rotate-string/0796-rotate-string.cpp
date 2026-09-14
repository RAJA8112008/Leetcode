class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return false;
        string news = s+s;
        return news.find(goal)!=string::npos;
    }
};