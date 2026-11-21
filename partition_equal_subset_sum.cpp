class Solution {
public:
    //hume 2 subsets ka sum equal bola h jo pue array ko cover krta h so iske liye pure array ka sum bhi even hona hoga but phir bhi not sure ki subset banega hi but if not even surely nhi banega
    bool f(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        if(i==0){
            return nums[0]==target;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool ntake=f(i-1,target,nums,dp);
        bool take=false;
        if(nums[i]<=target){
            take=f(i-1,target-nums[i],nums,dp);
        }
        return dp[i][target]= ntake || take;
        
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        //total jisse  target we will know
        if(total%2!=0){
            return false;
        }
        //subset sum 
        int target=total/2;
        //we are only checling ki 1 subset exist krta h ki nhi as ek krega toh baaki ka 2nd subset hi hoga we dont have to check 
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(n-1,target,nums,dp);
        
    }
};
