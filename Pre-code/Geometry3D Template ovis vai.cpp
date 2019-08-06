#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define pi acos(-1.0)
int cmp(double x)
{
    if(fabs(x) < EPS) return 0;
    return x < 0 ? -1 : 1;
}
struct PT{
    double x, y, z;
    PT(){x = y = 0; }
    PT(double _x, double _y, double _z) {x = _x, y = _y, z = _z; }
    PT operator-(const PT &a) const{
        return PT(x - a.x, y - a.y, z - a.z);
    }
    PT operator+(const PT &a) const{
        return PT(x + a.x, y + a.y, z + a.z);
    }
    PT operator*(double a) const{
        return PT(x * a, y * a, z * a);
    }
    PT operator/(double a) const{
        return PT(x / a, y / a, z / a);
    }
    PT unit()
    {
        return (*this) / val();
    }
    double val()
    {
        return sqrt(x * x + y * y + z * z);
    }
    void scan()
    {
        scanf("%lf %lf %lf", &x, &y, &z);
    }
    void print()
    {
        printf("(%.4f, %.4f, %.4f)", x, y, z);
    }
};

double dist(PT a, PT b)
{
    return (a - b).val();
}

double dist2(PT a, PT b)
{
    a = a - b;
    return a.x * a.x + a.y * a.y + a.z * a.z;
}
double dot(PT a, PT b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
PT cross(PT a, PT b)
{
    return PT(a.y * b.z - b.y * a.z, b.x * a.z - a.x * b.z, a.x * b.y - a.y * b.x);
}
double DistancePointSegment(PT a, PT b, PT c)
{
    //a.print(); b.print(); c.print();
    //cout << endl;
    //return dist(a, c);
    if(cmp(dot(b-a, c-a)) < 0) return dist(a, c);
    if(cmp(dot(a-b, c-b)) < 0) return dist(b, c);
    return fabs(cross((b-a).unit(), c-a).val());
}
double TriArea(PT a, PT b, PT c)
{
    return 0.5 * fabs(cross(b-a, c-a).val());
}
double TriToPointDistance(PT a, PT b, PT c, PT d)
{
    PT norm = cross(b-a, c-a).unit();
    PT ana = cross(b-a, norm);
    int f = 0;
    if(cmp(dot(ana, d-a)) > 0) f = 1;
    ana = cross(c-b, norm);
    if(cmp(dot(ana, d-b)) > 0) f = 1;
    ana = cross(a-c, norm);
    if(cmp(dot(ana, d-c)) > 0) f = 1;
    if(f==0) {
        PT ad = d - a;
        return fabs(dot(ad, norm));
    } else{
        return min(DistancePointSegment(a, b, d), min(DistancePointSegment(b, c, d), DistancePointSegment(c, a, d)));
    }
}
const double big = 1000000000000000.0;
double TriToSegmentDistance(PT a, PT b, PT c, PT d, PT e)
{
    double l = 0.0, r = 1.0;
    int cnt = 50;
    double ret = big;
    while(cnt--)
    {
        double mid1 = l + (r-l)/3.0, mid2 = r - (r-l)/3.0;
        double x = TriToPointDistance(a, b, c, d + (e-d)*mid1);
        double y = TriToPointDistance(a, b, c, d + (e-d)*mid2);
        if(x < y){
            r = mid2;
            ret = x;
        } else{
            ret = y;
            l = mid1;
        }
    }
    return ret;
}

double TriToTriDistance(PT a, PT b, PT c, PT d, PT e, PT f)
{
    double ret = big;
    ret = min(ret, TriToSegmentDistance(a, b, c, d, e));
    ret = min(ret, TriToSegmentDistance(a, b, c, e, f));
    ret = min(ret, TriToSegmentDistance(a, b, c, f, d));
    ret = min(ret, TriToSegmentDistance(d, e, f, a, b));
    ret = min(ret, TriToSegmentDistance(d, e, f, b, c));
    ret = min(ret, TriToSegmentDistance(d, e, f, c, a));
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n = 4;
        vector<PT> vtA(4), vtB(4);
        for(int i = 0; i<n; i++)
            vtA[i].scan();
        for(int i = 0; i<n; i++)
            vtB[i].scan();
        double ans = big;
        for(int i = 0; i<n; i++)
        for(int j = i+1; j<n; j++)
        for(int k = j+1; k<n; k++){
            PT a = vtA[i], b = vtA[j], c = vtA[k];
            for(int _i = 0; _i<n; _i++)
            for(int _j = _i+1; _j<n; _j++)
            for(int _k = _j+1; _k<n; _k++){
                PT d = vtB[_i], e = vtB[_j], f = vtB[_k];
                ans = min(ans, TriToTriDistance(a, b, c, d, e, f));
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
