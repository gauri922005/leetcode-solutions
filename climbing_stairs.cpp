class Solution {
public:
    //fiboncci dp 
    int climbStairs(int n) {
        int prev2=1;
        int prev=1;
        for(int i=2;i<=n;i++){
            //store all possible ways unique
            int curri=prev2+prev;
           
            prev2=prev;
            prev=curri;
        }

        return prev;
        
    }
};
