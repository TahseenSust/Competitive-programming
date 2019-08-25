void djkstra(int s)
{
    int dis[500];
    for(int i=0;i<500;i++) dis[i]=5000005;

    dis[s]=0;
    priority_queue<pair<int,int>>q;
    q.push({0,s});

    while(!q.empty()){
        pair<int,int>u=q.top();
        q.pop();

        for(int i=0;i<G[u.second].size();i++){
            pair<int,int>v=G[u.second][i];
            if(dis[v.first]>dis[u.second]+v.second){
                dis[v.first]=v.second+dis[u.second];
                q.push({-dis[v.first],v.first});
            }
        }
    }
    for(int i=0;i<500;i++){
        shortest_path[s][i]=dis[i];
    }
}
