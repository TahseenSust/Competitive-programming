/**
--------- -    |   |  /--  ----- ----- |\   |
    |    / \   |___| /__   |___  |___  | \  |
    |   /---\  |   |    /  |     |     |  \ |
    |  /     \ |   | __/   |____ |____ |   \|
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf scanf
#define pf printf

int arr[1000000];
void initialize(int N)
{
    for(int i=0;i<=N;i++){
        arr[i]=i;
    }
}

int root(int i)
{
    while(arr[i]!=i){
        i=arr[i];
    }
    return i;
}

void connect(int i,int j)
{
    int root_i=root(i);
    int root_j=root(j);
    arr[root_i]=root_j;
}

bool Find(int i,int j)
{
    return (root(i)==root(j));
}
int main()
{
    //freopen("input.txt","r",stdin);
	int T;
	bool flag=false;
	cin>>T;
	string cm;
	char d;
	int N,u,v;
	while(T--){
        if(flag){
            cout<<endl;
        }
        flag=true;
        cin>>N;
        initialize(N);
        int c=0,n=0;
        getline(cin,cm);
        while(getline(cin,cm) && cm!=""){
           d=cm[0];
           int i=2;
           u=0,v=0;
           while(cm[i]!=' '){
                u=u*10+(cm[i]-'0');
                i++;
           }
           i++;
           while(cm[i]){
                v=v*10+(cm[i]-'0');
                i++;
           }
           if(d=='c'){
                connect(u,v);
           }else{
                if(Find(u,v)){
                    c++;
                }else{
                    n++;
                }
           }
        }
        cout<<c<<","<<n<<endl;
	}
}
