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
    double x, y;
    PT(){x = y = 0; }
    PT(double _x, double _y) {x = _x, y = _y; }
    PT operator-(const PT &a) const{
        return PT(x - a.x, y - a.y);
    }
    PT operator+(const PT &a) const{
        return PT(x + a.x, y + a.y);
    }
    PT operator*(double a) const{
        return PT(x * a, y * a);
    }
    PT operator/(double a) const{
        return PT(x / a, y / a);
    }
    double val()
    {
        return sqrt(x * x + y * y);
    }
    PT unit()
    {
        return (*this) / val();
    }
    void scan()
    {
        scanf("%lf %lf", &x, &y);
    }
    void print()
    {
        printf("(%.4f, %.4f)", x, y);
    }
};
struct line{
    double a, b, c;
};

double dist(PT a, PT b)
{
    return (a - b).val();
}

double dist2(PT a, PT b)
{
    a = a - b;
    return a.x * a.x + a.y * a.y;
}
double dot(PT a, PT b)
{
    return a.x * b.x + a.y * b.y;
}
double cross(PT a, PT b)
{
    return a.x * b.y - a.y * b.x;
}
PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}
PT RotateCW90(PT p)
{
    return PT(p.y,-p.x);
}
PT RotateCCW(PT p, double t)
{
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}
PT RotateCW(PT p, double t)
{
    return PT(p.x*cos(t)+p.y*sin(t), -p.x*sin(t)+p.y*cos(t));
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c)
{
    double r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c)
{
    return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
// returns bisector of angle YXZ
line bisector(PT Y, PT X, PT Z)
{
    PT xy = (Y - X)/(Y - X).val();
    PT xz = (Z - X)/(Z - X).val();
    PT d = xy + xz;
    line ret{d.y, -d.x, d.x * X.y - d.y * X.x};
    return ret;
}

vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r)
{
    vector<PT>ret;
    b=b-a;
    a=a-c;

    double A=dot(b, b);
    double B=dot(a, b);
    double C=dot(a, a)-r*r;
    double D=B*B-A*C;

    if(D<-EPS) return ret;

    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);

    if(D>EPS) ret.push_back(c+a+b*(-B-sqrt(D))/A);

    return ret;
}
PT ComputeLineIntersection(PT a, PT b, PT c, PT d)
{
    double a1=a.y-b.y;
    double b1=b.x-a.x;
    double c1=cross(a, b);
    double a2=c.y-d.y;
    double b2=d.x-c.x;
    double c2=cross(c, d);
    double D=a1*b2-a2*b1;

    return PT((b1*c2-b2*c1)/D, (c1*a2-c2*a1)/D);
}
const double big = 100000000000000000.0;
vector<PT> CircleTouchingPoints(PT c, double r, PT a)
{
    double d = dist(c, a);
    double angle = asin(r/d);
    double length = sqrt(d*d - r*r);
    PT ac = c-a;
    ac = RotateCCW(ac, angle);
    ac = ac / ac.val() * length;
    vector<PT> ret;
    ret.push_back(a+ac);
    ac = c-a;
    ac = RotateCCW(ac, -angle);
    ac = ac / ac.val() * length;
    ret.push_back(ac + a);
    return ret;
}

double CircleArcDistance(PT c, double r, PT a, PT b)
{
    double d = dist(a, b);
    double angle = acos((2.0*r*r - d*d) / (2.0*r*r));
    return r * angle;
}
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R)
{
    vector<PT> ret;
    double d = sqrt(dist2(a, b));
    if (d > r+R || d+min(r, R) < max(r, R)) return ret;
    double x = (d*d-R*R+r*r)/(2*d);
    double y = sqrt(r*r-x*x);
    PT v = (b-a)/d;
    ret.push_back(a+v*x + RotateCCW90(v)*y);
    if (y > 0)
        ret.push_back(a+v*x - RotateCCW90(v)*y);
    return ret;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        PT a, b, c;
        double r;
        a.scan();
        b.scan();
        scanf("%lf", &r);
        c = PT(0, 0);
        double ans = big;
        if(DistancePointSegment(a,b,c) >= r) ans = dist(a, b);
        auto vtA = CircleTouchingPoints(c, r, a);
        auto vtB = CircleTouchingPoints(c, r, b);
        for(int i = 0; i<2; i++)
        {
            for(int j = 0; j<2; j++)
            {
                double d = dist(a, vtA[i]) + dist(b, vtB[j]) + CircleArcDistance(c, r, vtA[i], vtB[j]);
                ans = min(ans, d);
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}



