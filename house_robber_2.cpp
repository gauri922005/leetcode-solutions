class Solution {
public:
    //here the same thing as house 1 just that we cant take 1st and last index at same time so two time calling the function ince by excluding 1st(0) index and once by excluding last index
    int f(vector<int>&nums,vector<int>&dp, int i){
        if(i==0){
            return nums[0];
        }
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int pick=nums[i]+f(nums,dp,i-2);
        int npick=0+f(nums,dp ,i-1);
        return dp[i]=max(npick, pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
    }
       
        
        vector<int>temp1,temp2;
        
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        


        }
        vector<int>dp1(temp1.size(),-1);
        vector<int>dp2(temp2.size(),-1);
        return max(f(temp1,dp1,temp1.size()-1),f(temp2,dp2,temp2.size()-1));

        
    }
};
