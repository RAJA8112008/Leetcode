class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n==k)return "0";
        string st="";
        for(int i=0;i<n;i++){
            while(!st.empty() && st.back()>num[i] && k>0){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        // //if k is not zero then remove 
        while(k>0){
            st.pop_back();
            k--;
        }
        //remove leading zeros 
        int i=0;
        while(i<st.size() && st[i]=='0'){
            i++;
        }
        st=st.substr(i);
         if(st.empty())return "0";
        return st;
    }
};