#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXV 100000
#define MAXE 2 * MAXV

int to[MAXE],W[MAXE],nxt[MAXE],last[MAXV],E;

void add_edge(int u, int v, int w){
    to[E] = v; W[E] = w; nxt[E] = last[u]; last[u] = E++;
    to[E] = u; W[E] = w; nxt[E] = last[v]; last[v] = E++;
}


void dfs(int cur, int par, int s){
    for(int e = last[cur];e != -1;e = nxt[e])
        if(to[e] != par)
            dfs(to[e],cur,s ^ W[e]);
}


int main(){
    int N;
    scanf("%d",&N);
    memset(last,-1,sizeof last);
    E = 0;

    for(int i = 1,u,v,w;i < N;++i){
        scanf("%d %d %d",&u,&v,&w);
        add_edge(u,v,w);
    }

    dfs(0,-1,0);


    return 0;
}
