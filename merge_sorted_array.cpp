class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //push from behind 
        //3 pointers
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
            }
            else{
                nums1[k]=nums2[j];
                j--;
            }
            k--;
        }
        //if j exhausts still i ie nums1 will be valid from first while but if i exhausts first we need this second while to actually make nums1 valid merge
        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;

        }
        
    }
};
