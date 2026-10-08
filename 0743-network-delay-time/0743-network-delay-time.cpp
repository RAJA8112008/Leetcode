class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create an adj List 
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            //directed graph 
            adj[u].push_back({v,w});
        }
        //creaet an dist 
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int time=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            //move its nbr 
            for(auto nbr:adj[u]){
                int v=nbr.first;
                int newtime=nbr.second;
                if(newtime+time<dist[v]){
                    dist[v]=newtime+time;
                    //push into the queue 
                    pq.push({newtime+time,v});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<dist.size();i++){
            if(dist[i]==INT_MAX)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};