#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,mx_sz=0;
    while(cin>>n){
        mx_sz=0;
        string str[115];
        for(int i=0;i<n;i++){
            cin>>str[i];
            int sz=str[i].size();
            mx_sz=max(mx_sz,sz);
        }
        sort(str,str+n);
    //    for(int i=0;i<n;i++){
    //        cout<<str[i]<<' '<<str[i].size()<<endl;
    //    }
        for(int j=1;j<=60;j++){
            printf("-");
        }
        printf("\n");
        int col=0,ch=0;
        while(ch<=60){
            if(ch+(mx_sz+2)<=60){
                ch+=(mx_sz+2);
                col++;

            }else if(ch+mx_sz<=60){
                ch+=mx_sz;
                col++;
            }else{
                break;
            }
        }
        //cout<<col<<endl;
        int i=0,c=1,d=(int)ceil((double)n/(double)col),k=0,j=0;
        while(i!=n){
            if(k>=n){
                j++;
                k=j;
                c=0;
                printf("\n");
            }
            if(c>=col || i==n-1 || k+d>=n){
                printf("%s",str[k].c_str());
                int sp=mx_sz-str[k].size();
                while(sp--){
                    printf(" ");
                }
                printf("\n");
                j++;
                k=j;
                c=0;
            }else{
                printf("%s",str[k].c_str());
                int sp=mx_sz-str[k].size()+2;
                while(sp--){
                    printf(" ");
                }
                //cout<<"k="<<k<<endl;
                k+=d;
            }
            c++;
            i++;
        }
        if(c!=1){
            printf("\n");
        }
    }
}
