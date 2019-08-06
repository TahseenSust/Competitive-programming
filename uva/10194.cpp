#include<bits/stdc++.h>
using namespace std;
struct dt{
    char team_name[40];
    int point,win,los,drw,goal_ag,goal_soc,mat;
};
bool cmp(dt a,dt b)
{
    if(a.point==b.point){
        if(a.win==b.win){
            if(a.goal_soc-a.goal_ag==b.goal_soc-b.goal_ag){
                if(a.goal_soc==b.goal_soc){
                    if(a.mat==b.mat){
                        for(int i=0;a.team_name[i];i++){
                            a.team_name[i]=tolower(a.team_name[i]);
                        }
                        for(int i=0;a.team_name[i];i++){
                            b.team_name[i]=tolower(b.team_name[i]);
                        }
                        return strcmp(a.team_name, b.team_name)<0;

                    }
                    return a.mat<b.mat;
                }
                return a.goal_soc>b.goal_soc;
            }
            return a.goal_soc-a.goal_ag>b.goal_soc-b.goal_ag;
        }
        return a.win>b.win;
    }
    return a.point>b.point;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int N,T,G,a,b;
    bool f=0;
    map<string,int> mp;
    cin>>N;
    while(N--){
        mp.clear();
        char tournament_name[150],x[150],y[150],q[150];
        dt teams[1000];
        memset(teams,0,sizeof(teams));
        scanf("%*c%[^\n]s",tournament_name);
        //cout<<tournament_name<<endl;
        cin>>T;
        for(int i=0;i<T;i++){
            scanf("%*c%[^\n]s",teams[i].team_name);
            //cout<<teams[i].team_name<<endl;
            mp[teams[i].team_name]=i;
        }
        cin>>G;
        while(G--){
            scanf("%*c%[^\n]s",q);
            char *ptr;
            ptr=strtok(q,"#@");
            strcpy(x,ptr);
            ptr=strtok(NULL,"#@");
            a=atoi(ptr);
            ptr=strtok(NULL,"#@");
            b=atoi(ptr);
            ptr=strtok(NULL,"#@");
            strcpy(y,ptr);
            teams[mp[x]].mat++;
            teams[mp[y]].mat++;
            teams[mp[x]].goal_soc+=a;
            teams[mp[y]].goal_soc+=b;
            teams[mp[x]].goal_ag+=b;
            teams[mp[y]].goal_ag+=a;
            //printf("%s---%d--%d---%s\n",x,a,b,y);
            if(a>b){

                teams[mp[x]].point+=3;
                teams[mp[x]].win+=1;
                teams[mp[y]].los+=1;
                //printf("***%s****%d\n",teams[mp[x]].team_name,teams[mp[x]].point);
            }else if(b>a){
                teams[mp[y]].point+=3;
                teams[mp[y]].win+=1;
                teams[mp[x]].los+=1;
            }else{
                teams[mp[y]].point+=1;
                teams[mp[x]].point+=1;
                teams[mp[x]].drw+=1;
                teams[mp[y]].drw+=1;
            }
        }
        sort(teams,teams+T,cmp);
        if(f) printf("\n");
        f=1;
        printf("%s\n",tournament_name);
        for(int i=0;i<T;i++){
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,teams[i].team_name,teams[i].point,teams[i].mat,teams[i].win,teams[i].drw,teams[i].los,teams[i].goal_soc-teams[i].goal_ag,teams[i].goal_soc,teams[i].goal_ag);
        }
    }
}
