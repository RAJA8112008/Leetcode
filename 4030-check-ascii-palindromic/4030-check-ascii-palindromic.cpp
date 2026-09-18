class Solution {
public:
    bool isPalindromic(string s) {
         string binary="";
       //first change the char into bit 
        for(char ch:s){
            int asci=(int)ch;//'A'-->65
            //now change into the binary form 
           
            for(int i=7;i>=0;i--){
                binary+=((asci>>i)& 1)+'0';
            }
            
        }
        int left=0;
        int right=binary.length()-1;
        while(left<right){
            if(binary[left]!=binary[right])return false;
            left++;
            right--;
        }
        return true;
    }
};