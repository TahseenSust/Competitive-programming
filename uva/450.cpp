#include<bits/stdc++.h>
using namespace std;
struct dt{
    string infor[10];
};
bool cmp(dt a,dt b)
{
    return a.infor[2]<b.infor[2];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k=0;
    while(cin>>n){
        dt info[8000];

        k=0;
        string dept,str;
        getline(cin,dept);
        while(n--){
            getline(cin,dept);
            while(getline(cin,str)){
                if(str.size()==0){
                    break;
                }
                string wrd="";
                int d=0;
                for(int i=0;i<str.size();i++){
                    if(str[i]==','){
                        info[k].infor[d]=wrd;
                        d++;
                        wrd="";
                    }else{
                        wrd+=str[i];
                    }
                }
                info[k].infor[d]=wrd;
                d++;
                wrd="";
                info[k].infor[d]=dept;
                d++;
                k++;
            }
        }
        stable_sort(info,info+k,cmp);

        for(int i=0;i<k;i++){
            printf("----------------------------------------\n");
            cout<<info[i].infor[0];
            for(int j=1;j<3;j++){
                cout<<' '<<info[i].infor[j];
            }
            cout<<endl;
            for(int j=3;j<4;j++){
                cout<<info[i].infor[j];
            }
            cout<<endl;
            cout<<"Department: "<<info[i].infor[7]<<endl;
            cout<<"Home Phone: "<<info[i].infor[4]<<endl;
            cout<<"Work Phone: "<<info[i].infor[5]<<endl;
            cout<<"Campus Box: "<<info[i].infor[6]<<endl;
        }
    }
}
