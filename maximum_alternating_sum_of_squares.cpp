class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>s;
        for(auto it:nums){
            s.push_back(1LL*it*it);
        }
        sort(s.begin(),s.end());
        long long res=0;
        int n=nums.size();
        //add the larger half
        for(int i=n/2;i<n;i++){
            res+=s[i];
        }
        //substract the smaller half
        for(int i=0;i<n/2;i++){
            res-=s[i];

        }
        return res;
        
    }
};
