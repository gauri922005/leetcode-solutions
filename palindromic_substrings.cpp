class Solution {
public:
    //same as longest palindromic substring (easier)
    int countSubstrings(string s) {
        int n=s.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                maxlen++;
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                maxlen++;
                l--;
                r++;
            }
        }
        return maxlen;


        
    }
};
