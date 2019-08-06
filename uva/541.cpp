#include<bits/stdc++.h>
using namespace std;

bool check(int arr[][105],int n,int m)
{
    int s=0;
    for(int i=0;i<n;i++){
        s=0;
        for(int j=0;j<n;j++){
            s+=arr[j][i];
        }
        if(s%2==1){
            return false;
        }
    }
    for(int i=0;i<n;i++){
        s=0;
        for(int j=0;j<n;j++){
            s+=arr[i][j];
        }
        if(s%2==1){
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    while(cin>>n && n){
        int arr[105][105];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        bool flag=1;
        if(check(arr,n,n)){
            cout<<"OK\n";
        }else{
            for(int i=0;i<n && flag;i++){
                for(int j=0;j<n;j++){
                    arr[i][j]=!arr[i][j];
                    if(check(arr,n,n)){
                        printf("Change bit (%d,%d)\n",i+1,j+1);
                        flag=0;
                        break;
                    }
                    arr[i][j]=!arr[i][j];
                }
            }
            if(flag){
                printf("Corrupt\n");
            }
        }
    }
}
