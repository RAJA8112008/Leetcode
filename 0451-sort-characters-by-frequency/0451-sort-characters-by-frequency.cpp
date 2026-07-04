class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> mp;

        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        vector<pair<int,char>> vec;

        for(auto val:mp){
            vec.push_back({val.second,val.first});
        }

        sort(vec.begin(),vec.end());

        string ans="";

        for(int i=vec.size()-1;i>=0;i--){

            int freq = vec[i].first;

            for(int j=0;j<freq;j++){
                ans += vec[i].second;
            }
        }

        return ans;
    }
};