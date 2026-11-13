class Solution {
public:
    //yaha pe i ke saath jab sirf i check hoga toh agle ke liye check krna ie i+1 ke liye recursively phir jab i ke saath uska agle validate ho jaayega as two dight toh unke agle ko ie i+2 so one matlab i ka individual nhi balki uske agle ka individual aur i+2 matlba teo digit ke agle ka one aur two
    int f(string &s,vector<int>&dp, int i){
        if(i==s.size()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=f(s,dp,i+1);
        int two=0;
        if(i+1<s.size()){
            int num=(s[i]-'0')*10 + s[i+1]-'0';
            if(num>=10 && num<=26){
                two=f(s,dp,i+2);
            }
        }
        return dp[i]= one+two;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return f(s,dp, 0);
        
    }
};
