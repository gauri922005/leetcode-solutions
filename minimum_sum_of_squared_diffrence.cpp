class Solution {
public:
    //saare possible diff ko check kron with thier freq on track 
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>freq(100001,0);
        long long k=(long long)k1+k2;
        //absolute diffrence and update how many times differnce occurs
        for(int i=0;i<nums2.size();i++){
            int d=abs(nums1[i]-nums2[i]);
            freq[d]++;
        }
        //loop goes from max element ie max difference that can possibly happen to lowest as max is priortised for modification(decrease)
        for(int d=100000;d>0 && k>0;d--){
            if(freq[d]==0){
                continue;
            }
            int move=min((long long)freq[d],k);
            freq[d]-=move;
            //only the diffrence one less would be incresed as suppose 4 difference has 3 freq and k=2 then just decresing 3-2=1 so 4 4 4 becomes 3 3 4 rather then 2 4 4
            freq[d-1]+=move;
            k-=move;
        }
        long long res=0;
        //freq pe work hoga loop
        for(int i=1;i<=100000;i++){
            //1LL to neutralise if the sum goes beyong int as i is int also freq so that we dont multiply /diff that did not occur nad if occured multiple time than too ok
            res+=1LL*i*i*freq[i];
        }
        return res;


    }
};
