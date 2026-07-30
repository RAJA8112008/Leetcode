class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if(n<=8){
            return n;     
           }
        int ans=0;
        int div = n/8;
        int rem=n%8;
        while(div>0){
            if(rem != 0){
                ans+=((div+1)*rem);
                rem=0;
            }
            ans+=(div*8);
            div--;
        }
        return ans;
    }
};