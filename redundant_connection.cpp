//use karo dsu union ko bool ban kar jb bhi ulp same hoga mtlab woh edge hi extra h return false 
class dsu{
public:
    vector<int>size,parent;


    dsu (int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
            }
        }
    int findup(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findup(parent[node]);
    }
    bool unionsize(int u,int v){
        int ulpu=findup(u);
        int ulpv=findup(v);
        if(ulpu==ulpv){
            return false;
        }
        if(size[ulpu]>size[ulpv]){
            parent[ulpv]=ulpu;
            size[ulpu]+=size[ulpv];
          
        }
        else{
            parent[ulpu]=ulpv;
            size[ulpv]+=size[ulpu];
            
        }
        return true;
        
    }
    

    
};
class Solution {
public:


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        dsu ds(n);
        for(auto it:edges){
            if(!ds.unionsize(it[0],it[1])){
                return it;
            }
        }
        return {};
    }
    
};
