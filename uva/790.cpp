#include<bits/stdc++.h>
using namespace std;

struct dt{
    int id,h,m;
    char pro,ver;
};
struct dt2{
    int id,p=0,t=0;
};
bool cmp(dt a,dt b)
{
    if(a.id==b.id){
        if(a.pro==b.pro){
            if(a.h==b.h){
                if(a.m==b.m){
                    return a.ver<b.ver;
                }
                return a.m<b.m;
            }
            return a.h<b.h;
        }
        return a.pro<b.pro;
    }
    return a.id<b.id;
}

bool cmp2(dt2 a,dt2 b)
{
    if(a.p==b.p){
        if(a.t==b.t){
            return a.id<b.id;
        }
        return a.t<b.t;
    }
    return a.p>b.p;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    string inp;
    getline(cin,inp);
    getline(cin,inp);
    while(t--){
        dt info[1000];
        char emne;
        int n=0;
        while(getline(cin,inp)){
            if(inp.size()==0)
                break;
            int d=0,l=0;
            while(inp[l]!=' '){
                d=d*10+(inp[l]-'0');
                l++;
            }
            l++;
            info[n].id=d;
            info[n].pro=inp[l];
            l++;
            l++;
            d=0;
            while(inp[l]!=':'){
                d=d*10+(inp[l]-'0');
                l++;
            }
            l++;
            info[n].h=d;
            d=0;
            while(inp[l]!=' '){
                d=d*10+(inp[l]-'0');
                l++;
            }
            l++;
            info[n].m=d;
            info[n].ver=inp[l];
            n++;
        }
        sort(info,info+n,cmp);
//        for(int i=0;i<n;i++){
//            printf("%d %c %d:%d %c\n",info[i].id,info[i].pro,info[i].h,info[i].m,info[i].ver);
//        }
        int cur_team=0,cur_prob,p,k=-1;
        dt2 board[25];
        for(int i=0;i<n;){
            if(cur_team!=info[i].id){
                k++;
                cur_team=info[i].id;
                cur_prob=info[i].pro;
                p=0;
                board[k].id=cur_team;
            }
            if(cur_prob!=info[i].pro){
                cur_prob=info[i].pro;
                p=0;
            }
            if(info[i].ver=='N'){
                p+=20;
            }
            if(info[i].ver=='Y'){
                board[k].p++;
                board[k].t+=(info[i].h*60+info[i].m+p);
                while(info[i].pro==cur_prob && info[i].id==cur_team && i<n){
                    i++;
                }
            }else{
                i++;
            }
        }
        sort(board,board+k+1,cmp2);
        for(int i=1;i<=info[n-1].id;i++){
            bool f=0;
            for(int j=0;j<=k;j++){
                if(board[j].id==i){
                    f=1;
                    break;
                }
            }
            if(f==0){
                k++;
                board[k].id=i;
            }
        }
        sort(board,board+k+1,cmp2);
        printf("RANK TEAM PRO/SOLVED TIME\n");
        int rnk=0,ap=100,a_t=-1;
        for(int i=0;i<=k;i++){
            if(board[i].p<ap){
                rnk=i+1;
            }else if(board[i].t>a_t){
                rnk=i+1;
            }
            ap=board[i].p;
            a_t=board[i].t;
            if(board[i].p==0){
                board[i].p=NULL;
            }
            if(board[i].t==0){
                board[i].t=NULL;
            }
            printf("%4d %4d",rnk,board[i].id);
            if(board[i].p>0)
                printf(" %4d       %4d",board[i].p,board[i].t);

            printf("\n");

        }
        if(t)
            printf("\n");
    }
}
