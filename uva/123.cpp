#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<string,int>,string>a,pair<pair<string,int>,string>b)
{
    return a.first.first<b.first.first;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string ignor[55];
    map<string,bool>trak;
    pair<pair<string,int>,string>store[55*210];
    int k=0,w=0;
    while(cin>>ignor[k]){
        if(ignor[k]=="::"){
            break;
        }
        trak[ignor[k]]=1;
        k++;
    }
    string tile[210];
    int z=0;
    while(getline(cin,tile[w])){
        string wrd;
        tile[w]+=" ";
        int k=0;
        for(int i=0;i<tile[w].size();i++){
            if(tile[w][i]==' '){
                if(trak[wrd]==0){
                    store[z].first.first=wrd;
                    store[z].first.second=k;
                    //tile[w]=tile[w].substr(0,tile[w].size());
                    store[z].second=tile[w];
                    z++;
                }
                k=i+1;
                wrd="";
            }else{
                wrd+=tolower(tile[w][i]);
            }
        }
        w++;
    }
    stable_sort(store,store+z,cmp);
    for(int i=0;i<z;i++){
        for(int j=0;j<store[i].second.size();j++){
            int x=0,y=j;
            store[i].second[j]=tolower(store[i].second[j]);
            if(store[i].first.second==j){
                while(store[i].first.first[x]==store[i].second[y]){
                    x++,y++;
                    store[i].second[y]=tolower(store[i].second[y]);
                    if(x==store[i].first.first.size()){
                        break;
                    }
                }
            }
            //cout<<x<<endl;
            if(x==store[i].first.first.size()){
                while(store[i].second[j]!=' '){
                    printf("%c",toupper(store[i].second[j]));
                    j++;
                }
            }else{
                while(store[i].second[j]!=' '){
                    printf("%c",tolower(store[i].second[j]));
                    j++;
                }
            }
            if(store[i].second[j]==' '){
                if(j!=store[i].second.size()-1)
                cout<<' ';
            }
        }
        if(store[i].second.size()>1){
            cout<<endl;
        }
    }
}
