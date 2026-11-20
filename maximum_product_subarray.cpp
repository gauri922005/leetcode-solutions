class Solution {
public:
    //not by dp refer book 
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int prefix=1;
        int suffix=1;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(prefix==0){
                prefix=1;
            }
            if(suffix==0){
                suffix=1;
            } 
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1];
            int z=max(prefix,suffix);
            maxi=max(z,maxi);

            }
            return maxi;
    }
};
