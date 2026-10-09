class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //create an map to store the freq 
        unordered_map<char,int>freq;
        int n=s.size();
        int maxlen=0;
       int i=0;
       int j=0;
       while(j<n){
            char ch=s[j];
            while(freq[s[j]]>0){
                freq[s[i]]--;
                i++;
            }
             maxlen=max(maxlen,j-i+1);
              freq[ch]++;
            j++;
       }
     return maxlen;
    }
};