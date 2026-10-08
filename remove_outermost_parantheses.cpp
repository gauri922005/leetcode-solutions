class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string res="";
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
            }
            if(st.empty()){
                //wrong answers when substr(1,4)
                res+=temp.substr(1,temp.size()-2 );
                temp="";
            }

        }
        return res;
       
        
    }
};
