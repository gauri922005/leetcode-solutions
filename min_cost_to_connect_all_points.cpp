class Solution {
public:
    //kruskals se solve kiya h 
    class dsu{
        vector<int>parent,size;
    public:
        dsu(int n){
            parent.resize(n);
            size.resize(n);
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
        void ubysize(int u,int v){
            int ulpu=findup(u);
            int ulpv=findup(v);
            if(ulpu==ulpv){
                return ;
            }
            if(size[ulpu]<size[ulpv]){
                parent[ulpu]=ulpv;
                size[ulpv]+=size[ulpu];
            }
            else{
                parent[ulpv]=ulpu;
                size[ulpu]+=size[ulpv];
            }
        }


    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>>z;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt=abs(points[i][0]-points[j][0])+
                       abs(points[i][1]-points[j][1]);
                        z.push_back({wt,{i,j}});
            }
           
        }
        sort(z.begin(),z.end());
        dsu ds(n);
        int sum=0;
        //count kyuki kruskal mei edeges n-1 hoti h
        int count=0;
        for(auto it:z){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findup(u)!=ds.findup(v)){
                ds.ubysize(u,v);
                sum+=wt;
                count++;
                if(count==n-1){
                    break;
                }
            }
        }
        return sum;
        

        
        
    }
};
