class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //dijkstra
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int edgeweight=it.second;
                int adjnode=it.first;
                if(dis+edgeweight<dist[adjnode]){
                    dist[adjnode]=dis+edgeweight;
                    pq.push({dist[adjnode],adjnode});

                    }
            }
        }
        //we have to find maximum of smallest 
        int res=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                return -1;
            }
            res=max(dist[i],res);

        }
        return res;

        
    }
};
