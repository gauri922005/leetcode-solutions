class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //use 2 sets
        set<int>s;
        set<int>ans;
        for(int x:nums1){
            s.insert(x);
        }
        for(int x:nums2){
            if(s.find(x)!=s.end()){
                ans.insert(x);
            }
        }
        vector<int>res;
        for(int x:ans){
            res.push_back(x);
        }
        return res;

        
    }
};
