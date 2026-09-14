class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        int n =s.length();
         string word="";
        for(int i=0;i<n;i++){
            
            //skip spaces 
            while(i<n && s[i]==' '){
                i++;
            }
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            }
            //push it into words 
            if(word.size()>0){
                words.push_back(word);
            }
            word="";
        }
        //reverse the words vector
        reverse(words.begin(),words.end());
        //remove words from thw words vector and put into the ans 
        string ans="";
        for(int i=0;i<words.size();i++){
            ans+=words[i];
            //add space 
            if(i!=words.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};