class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        for(int i=0;i<s.length();i++){
            //first remove spaces 
            while(s[i]==' '){
                i++;
            }
            string word="";
            while(i<s.length() && s[i]!=' '){
              word+=s[i];
              i++;
            }
            if(!word.empty()){
            words.push_back(word);
            }
            //empty word
            word="";
        }
        //reverse the words vector 
        reverse(words.begin(),words.end());
        string ans="";
        for(int i=0;i<words.size();i++){
            ans+=words[i];
            //add space except last word
            if(i!=words.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};