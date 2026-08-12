class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //first store  all words to make them visited
        unordered_map<string,bool>mp;
        //push values in map  and mark them false;
        for(auto val:wordList){
            mp[val]=false;
        }
        //create a queue
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        mp[beginWord]=true;
        //pop values from the queue and apply BFS 
        while(!q.empty()){
            pair<string,int>temp=q.front();
            q.pop();
            string word=temp.first;
            int level=temp.second;
            if(word==endWord)return level;
            //now change its value and find in map
            for(int i=0;i<word.length();i++){
                string wordChange=word;
                for(char c='a';c<='z';c++){
                    //change the word 
                    wordChange[i]=c;
                    //search in map 
                    if(mp.find(wordChange)!=mp.end() && mp[wordChange]==false){
                        //push into queue 
                        q.push({wordChange,level+1});
                        mp[wordChange]=true;
                    }
                    
                }
            }
        }
        return 0;
    }
};