class Solution {
public:
 int stringTosecond(string startTime){
     string st="";
        int h=0;
        int m=0;
        int s=0;
         int i=0;
            //hours
            while(i<startTime.length() && startTime[i]!=':'){
                st+=startTime[i];
                i++;
            }
             h= stoi(st)*60*60;
             i++;
            //minute
            st=""; 
            while(i<startTime.length() && startTime[i]!=':'){
                st+=startTime[i];
                i++;
            }
            m=stoi(st)*60;
            i++;
            //second 
            st="";
            while(i<startTime.length() && startTime[i]!=':'){
                st+=startTime[i];
                i++;
            }
            s=stoi(st);
        return (h+m+s);
 }
    int secondsBetweenTimes(string startTime, string endTime) {
      return abs(stringTosecond(startTime)-stringTosecond(endTime));
    }
};