class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         unordered_map<char,int>mp;
         for(int i=0;i<ransomNote.size();i++){
            mp[ransomNote[i]]++;
         }

         for(auto val:magazine){
            if(mp.find(val)!=mp.end() && mp[val]>0){
                mp[val]--;
            }
         }

         for(auto val:mp){
            if(val.second!=0)return false;
         }
         return true;
    }
};