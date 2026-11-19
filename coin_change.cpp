class Solution {
public:
    //subsequence so take and notake
    int f(int i,int T , vector<int>&coins, vector<vector<int>>&dp){
        if(i==0){
            if(T%coins[0]==0){
                //take coins that much if divisible
                return T/coins[0];
            }
            return 1e9;

        }
        if(dp[i][T]!=-1){
            return dp[i][T];
        }
        int notake=f(i-1,T,coins,dp);
        //take=0 can lead to min being 0 
        int take=1e9;
        if(coins[i]<=T){
            //+1 as you will also take the coin itself
            take=1+f(i,T-coins[i],coins,dp);
        }
        return dp[i][T]= min(notake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res=f(n-1,amount, coins,dp);
        if(res>=1e9){
            return -1;
        }
        return res;
        
    }
};
