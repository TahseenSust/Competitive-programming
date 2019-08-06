#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD;

struct matrix{
    int v[10][10],row,col;
};


matrix multiply(const matrix &A,const matrix &B)
{
    matrix r;
    r.row = A.row;
    r.col = B.col;

    for(int i=0;i<r.row;i++){
        for(int j=0;j<r.col;j++){
            int sum=0;
            for(int k=0;k<A.col;k++){
                sum+=(A.v[i][k]*B.v[k][j]);
                sum%=MOD;
            }
            r.v[i][j]=sum;
        }
    }
    return r;
}

string binary(int n)
{
    string ret="";
    while(n){
        ret+=((n%2==0)?"0":"1");
        n/=2;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}


matrix power(matrix A,int p)
{
    string bin=binary(p);
    matrix ret=A;
    for(int i=1;i<bin.size();i++){
        ret=multiply(ret,ret);
        if(bin[i]=='1'){
            ret=multiply(ret,A);
        }
    }
    return ret;
}

int main()
{
    int t,a,b,n,m;
    cin>>t;

    while(t--){
        cin>>a>>b>>n>>m;
        matrix mat;
        mat.row=mat.col=2;
        mat.v[0][0]=mat.v[0][1]=mat.v[1][0]=1;
        mat.v[1][1]=0;
        MOD=1;
        for(int i=1;i<=m;i++){
            MOD*=10;
        }
        if(n<2){
            if(n==0) cout<<a<<endl;
            if(n==1) cout<<b<<endl;
        }else{
            mat=power(mat,n-1);
            int ans=(b*mat.v[0][0]+a*mat.v[0][1])%MOD;
            cout<<ans<<endl;
        }
    }

}
