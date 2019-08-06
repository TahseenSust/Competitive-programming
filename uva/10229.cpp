#include<bits/stdc++.h>
#include<cassert>
using namespace std;
#define ll long long
struct matrix
{
    ll v[5][5];
    ll row,col;
};
ll mod=10000;

matrix multiply(matrix a, matrix b)
{
    assert(a.col == b.row);
    matrix r;
    r.row = a.row;
    r.col = b.col;
    for(ll i = 0; i < r.row; i++)
    {
        for(ll j = 0; j < r.col; j++)
        {
            ll sum = 0;
            for(ll k = 0; k < a.col; k++)
            {
                sum += a.v[i][k] * b.v[k][j];
                sum %= mod;
            }
            r.v[i][j] = sum;
        }
    }
    return r;
}

matrix power(matrix mat, ll p)
{
    assert(p >= 1);
    if (p == 1) return mat;
    if (p % 2 == 1)
        return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p / 2);
    ret = multiply(ret, ret);
    return ret;
}

ll fast_power(ll num, ll p)
{
    if(p == 0) return 1;
    if (p == 1) return num;
    if (p % 2 == 1)
        return num*fast_power(num, p - 1);
    ll ret = fast_power(num, p / 2);
    ret = ret*ret;
    return ret;
}

int main()
{
    ll n;
    while(cin>>n>>mod)
    {
        matrix mat;
        mat.row=mat.col=2;
        mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
        mat.v[1][1] = 0;
        mod=fast_power(2,mod);
        if(n<3){
            if(n == 0) cout<<"0\n";
            else if(n == 1 || n == 2) cout<<1%mod<<endl;
        }else{
            mat = power(mat,n-2);
            ll ans = ((1 * mat.v[0][0])%mod + (1 * mat.v[0][1])%mod)%mod;
            cout<<ans<<endl;
        }
    }

}
