class Solution {
public:
    string sortString(string s) {
        //store freq 
        vector<int>store(26,0);
        for(int i=0;i<s.size();i++){
            store[s[i]-'a']++;
        }
       bool rightToleft=false;

        string result="";
     while(result.size()<s.size()){
       if(rightToleft==false){
           for(int i=0;i<store.size();i++){
            if(store[i]>0){
                result+=i+'a';
                store[i]--;
            }
           }
       }else
       {
            for(int i=25;i>=0;i--){
            if(store[i]>0){
                result+=i+'a';
                store[i]--;
            }
           }
       }
       rightToleft=!rightToleft;
        }
       return result;
    }
};