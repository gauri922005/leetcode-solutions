class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int z=0;
       
            for(int i=0;i<s.size();i++){
                if(s[i]=='('){
                    st.push(s[i]);
                }
                else{
                     if(st.empty()){
                        z++;
                     }
                     else {
                        st.pop();
                     }
                }
            }
            if(!st.empty()){
                z+=st.size();
            }
            return z;
        
      

        


    }
};
