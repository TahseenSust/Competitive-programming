#include<bits/stdc++.h>
using namespace std;

int road[102][102];
int dis[102];



bool bfs(int s,int e,int d)
{
    queue<int>q;
    memset(dis,-1,sizeof dis);
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int i=1;i<=100;i++){
            if(road[cur][i]){
                if(dis[cur]==2 && dis[i]!=2){
                    dis[i]=2;
                    q.push(i);
                }else if(dis[i]==-1){
                    dis[i]=dis[cur]^1;
                    q.push(i);
                }else if(dis[i]==0 && dis[cur]^1==1){
                    dis[i]=2;
                    q.push(i);
                }else if(dis[i]==1 && dis[cur]^1==0){
                    dis[i]=2;
                    q.push(i);
                }

            }
        }
    }
    return (dis[e]==2 || (dis[e]==(d&1)));
}


int main()
{
    int s,e,d,c,l,u,v;

    while(cin>>c>>l){

        if(c==0 && l==0) return 0;


        memset(road,0,sizeof road);

        for(int i=0;i<l;i++){
            cin>>u>>v;
            road[u][v]++;
            road[v][u]++;
        }

        cin>>s>>e>>d;

        if(bfs(s,e,d)){
            printf("Yes, Teobaldo can travel.\n");
        }else{
            printf("No, Teobaldo can not travel.\n");
        }
    }

}
