#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    
    ll x, y, g;

    if(a==0 && b==0){
        if(c==0){
            return abs((maxx-minx+1)*(maxy-miny+1));
        }
        return 0;
    }else if(a==0 || b==0){
        if (!find_any_solution(a, b, c, x, y, g))
            return 0;
        if(a==0){
            if(y>=miny && y<=maxy){
                return (maxx-minx+1);
            }
        }else if(b==0){
            if(x>=minx && x<=maxx){
                return (maxy-miny+1);
            }
        }
        return 0;
    }

    if (!find_any_solution(a, b, c, x, y, g))
        return 0;

    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);

    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);


    if (y > maxy)
        return 0;

    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);

    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);


    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

int main()
{
    ll a,b,c,x1=0,x2=INT_MAX,y1=0,y2=INT_MAX,p,g,x,y,z;
    int t;
    cin>>t;

    for(int tc=1;tc<=t;tc++){
        cin>>a>>b>>c>>p;

        ll ans=0;
        g=__gcd(__gcd(a,b),c);

        if(p%g==0){
            ll k=0;
            while(p-k*c>=0){
                ans+=find_all_solutions(a,b,p-k*c,x1,x2,y1,y2);
                k++;
            }
        }


        printf("Case %d: %lld\n",tc,ans);

    }

    /*

    all solution
    
    x'=x+k*(b/g)
    y'=y-k*(a/g)
    
    */
    
}
