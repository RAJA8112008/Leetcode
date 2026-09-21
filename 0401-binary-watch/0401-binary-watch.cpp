class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        //for hours 
        for(int hour=0;hour<12;hour++){
            //for minutes 
            for(int minute=0;minute<60;minute++){
                //find out all int-->binary-->1'scount;
                int count = __builtin_popcount(hour)
                          + __builtin_popcount(minute);
                if(count==turnedOn){
                    string time=to_string(hour)+":";
                    //leading Zeos 
                    if(minute<10){
                       time+="0";
                    }
                    time+=to_string(minute);
                    ans.push_back(time);
                }
                
            }
        }
       return ans;
    }
};