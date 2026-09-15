class Solution {
public:
    string frequencySort(string s) {
        //store freq of each char
        string ans="";
       unordered_map<char,int>freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        vector<pair<int,char>>store;
        for(auto val:freq){
            store.push_back({val.second,val.first});
        }
        sort(store.begin(),store.end());
        for(int i=store.size()-1;i>=0;i--){
            while(store[i].first!=0){
                ans+=store[i].second;
                store[i].first--;
            }
        }
        return ans;
    }
};