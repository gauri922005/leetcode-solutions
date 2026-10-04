class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int subhasa=0;
        //here loop changes when row ie subhasa changes so its not linear
        for(int i=1;i<n;i++){
            if(mat[subhasa][i]==1){
                subhasa=i;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=subhasa){
                //anyone from candidates row shouldnt be known by candidate also evryone in candidates column must know candidate
                //[subhasa][i] checks subhasa's row [1][0], [1][1], [1][2]  [i][subhasa] checks subhasa's columns [0][1], [1][1], [2][1]                i
                if(mat[subhasa][i]==1 ||mat[i][subhasa]==0){
                    return -1;
                }
            }
        }
        return subhasa;
    }
};
