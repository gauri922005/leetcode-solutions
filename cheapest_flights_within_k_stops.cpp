class Solution {
public:
    //dijskstra will fail as it focuses on cost not stops so we use bfs instead
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //classic way of creating graph ie adjacency lit for neighbours
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        //queue works also as pq as stops will increese in a constant manner ie +1 at a time so q.front() will always have samllest stops 
              //{stop,{node,cost}}
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            //as we dont anywauys want stops execeeding
            if(stop>k){
                continue;
            }
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;
                if(cost+edw<dist[adjnode] && stop<=k){
                    dist[adjnode]=cost+edw;
                    q.push({stop+1,{adjnode,dist[adjnode]}});

                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
        
    }
};
