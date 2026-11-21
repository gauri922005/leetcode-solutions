class Solution {
public:
    //the solution will explore ways but if it find a successful way first it will not check others as returing true matters
    bool f(int i, string s, unordered_set<string>&st, vector<int>&dp){
        //base case if reached here that means it is possible
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //start from 0 ie i
        for(int j=i;j<s.size();j++){
            //l le lee leet
            string temp=s.substr(i,j-i+1);
            if(st.find(temp)!=st.end()){
                //if leet is found now chect from  4 index on 
                if(f(j+1,s,st,dp)){
                    return dp[i]=1;
                    
                }
                
            }

        }
        return dp[i]=0;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(n+1,-1);
        return f(0,s,st,dp);
        
        
    }
};
