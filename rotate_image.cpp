class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose+reverse
        //in-place == swap
        int n=matrix.size();
        //transpose
        for(int i=0;i<n;i++){
            //nxn because j=0 will lead to swapping back to original
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reverse
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
        
    }
};
