class Solution {
public:
    //description se nhi samajta but hume subarray mei kitne unique element h unhe count krkr unka squares ka sum return krna h
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            unordered_set<int>s;
            for(int j=i;j<n;j++){
                s.insert(nums[j]);
                int unique =s.size();
                res+=unique*unique;
                
                            
                }
        }
        return res;
        
    }
};
