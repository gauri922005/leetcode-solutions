class Solution {
public:
    //two pointers not dp
    //try to make every indexes center and expand
    //even odd lenght palindrome 
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxlen=1;
        for(int i=0;i<n;i++){
            //odd length palindrome will have one center
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxlen){
                    start=l;
                    maxlen=r-l+1;
                }
                //expand
                l--;
                r++;
            }
            //even length palindrome will have 2 centers but same letter on them
            l=i;
            r=i+1;
            while(l>=0 && r<n &&s[l]==s[r]){
                if(r-l+1>maxlen){
                    start=l;
                    maxlen=r-l+1;
                }
                //expand
                l--;
                r++;
            }
        }
        return s.substr(start,maxlen);
        
    }
};
