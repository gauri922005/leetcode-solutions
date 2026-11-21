class Solution {
public:
    //previ is the also one you have to keep track of to see ki kisse bada you are seaching
    int f(int ind,int previ,vector<int>&nums, vector<vector<int>>&dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][previ+1]!=-1){
            return dp[ind][previ+1];
        }
        //0 is len mei increase kyuki liya toh no increase 
        //index either way aage badhega
        //previ is the index jisse bada element we have to find so as we are not taking this elemnet toh vompare iske previ se hi hoga
        int ntake=0+f(ind+1,previ,nums,dp);
        int take=0;
        //-1 is ony for first element we have to take it 
        if(previ==-1 || nums[ind]>nums[previ]){
            //+1 in length
            //previ current index banjaayega
            take=1+f(ind+1,ind,nums,dp);
            
        }
        int len=max(ntake,take);
        //dp mei previ -1 kaise express hoga isiliye coordinate shifting kiya h -1 jo h woh 0 pe store hoga 0 1 pe
        return dp[ind][previ+1]= len;
                
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //yeh 2d array ka aise ki har index ke liye hum usse previous se bad wala agar milta h toh uska length store karte h
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
        
    }
};
