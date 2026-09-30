class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_map<string,bool>mp;
        for(int i=0;i<n;i++){
            mp[wordList[i]]=false;
        }
        //ccreate an queue
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        mp[beginWord]=true;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            string word=temp.first;
            int level=temp.second;
            if(word==endWord)return level;
            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(mp.find(word)!=mp.end() && mp[word]==false){
                        q.push({word,level+1});
                        mp[word]=true;
                    }
                }
                word[i]=ch;
                
            }
        }
        return 0;
    }
};