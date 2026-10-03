class Solution {
public:
    int longestValidParentheses(string s) {
        
        int left=0;
        int right=0;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            //even lentgth
            if(left==right){
                maxi=max(left*2,maxi);
            }
            //new sub-string as this one has become invalid because of closings
            else if(right>left){
                right=0;
                left=0;
            }

            
        }
        //(() inavalid because of openings so reverse
        left=0;
        right=0;
          for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                maxi=max(left*2,maxi);
            }
            //.....
            else if(right<left){
                right=0;
                left=0;
            }

            
        }
        return maxi;
    }
};
