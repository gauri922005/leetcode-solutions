class Solution {
public:
    //bfs solution
    bool isvalid(string s){
        int count=0;
        for(char c:s){
            if(c=='('){
                count++;
            }
            else if(c==')'){
                count--;
            }
            if(count<0){
                return false;
            }
        }
        return count==0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string>res;
        unordered_set<string>vis;
        queue<string>q;
        //important kookie does the minimum check thing
        bool kookie=false;;
        q.push(s);
        vis.insert(s);
        while(!q.empty()){
            string z=q.front();
            q.pop();
            if(isvalid(z)){
                res.push_back(z);
                kookie=true;
            }
            //0 is minimum no need for removing further for this string as it is valid so skip
            //ek baar kookie ie found true ho gaya tph woh waapis false nhi hota h 
            if(kookie){
                continue;
            }
            //removal bfs har ek (,) ko ek baar remove krega aur strings generate krega
            for(int i=0;i<z.size();i++){
                if(z[i]!='(' && z[i]!=')'){
                    continue;
                }
                string next=z.substr(0,i)+z.substr(i+1);
                if(vis.find(next)==vis.end()){
                    vis.insert(next);
                    q.push(next);
                }
            }
        }
        return res;
        }
};
