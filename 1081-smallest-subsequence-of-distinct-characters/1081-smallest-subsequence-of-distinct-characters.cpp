class Solution {
public:
    string smallestSubsequence(string s) {
        //first store last occurence index of char to check it will agagin come in future or not 
        vector<int>lastoccurence(26);
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            lastoccurence[ch-'a']=i;
        }
        //visted array to check 
        vector<bool>visited(26,false);
        //create a stack for store lexicograph order 
        stack<char>st;
        //push values in stack 
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if (visited[ch - 'a']) continue;
            while(!st.empty() && st.top()>ch && lastoccurence[st.top()-'a']>i){
               //visited array->false
               visited[st.top()-'a']=false;
               st.pop();    
            }
            //push in stack and make visited true 
            st.push(ch);
            visited[ch-'a']=true;
        }
        //stack have answer 
        string ans="";
        while(!st.empty()){
            int val=st.top();
            st.pop();
            ans+=val;
        }
        //stack gives ans in reverse order so 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};