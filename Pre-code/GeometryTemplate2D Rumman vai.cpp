

#define PI acos(-1.0)

using namespace std;

const double INF = 1e100;
const double EPS = 1e-9;

int EQ(double x)
{
    if(fabs(x)<EPS) return 0;
    else if(x>0) return 1;
    else return -1;
}

struct PT
{
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (double c)     const
    {
        return PT(x/c,   y/c  );
    }
};

double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}
double dist2(PT p, PT q)
{
    return dot(p-q,p-q);
}
double distPoint(PT p, PT q)
{
    return sqrt(dot(p-q,p-q));
}
double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}
//ostream &operator<<(ostream &os, const PT &p)
//{
//    os << "(" << p.x << "," << p.y << ")";
//}

// rotate a point CCW or CW around the origin
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

// find a point from 'a' through 'b' with
// distance d
// use for better precision
PT PointAlongLine(PT a,PT b,double d)
{
    return a + (((b-a) / sqrt(dot(b-a,b-a))) * d);
}

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c)
{
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
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

///return minimum distance from point p to line AB
double distToLine(PT p, PT A, PT B, PT &c)
{
    double scale = (double)
                   (dot(p-A,B-A)) /
                   (dot(B-A,B-A));
    c.x = A.x + scale * (B.x - A.x);
    c.y = A.y + scale * (B.y - A.y);
    return distPoint(p, c);
}

///return minimum distance from point p to line segment AB
double distToLineSegment(PT p, PT A, PT B, PT &c)
{
    if (dot(B-A,p-A) < EPS)
    {
        c.x = A.x;
        c.y = A.y;
        return distPoint(p, A);
    }
    if (dot(A-B,p-B) < EPS)
    {
        c.x = B.x;
        c.y = B.y;
        return distPoint(p, B);
    }
    return distToLine(p, A, B, c);
}

bool isPointOnSegment(PT p,PT a,PT b)
{
    if(fabs(cross(p-b,a-b))<EPS)
    {
        if(p.x<min(a.x,b.x)||p.x>max(a.x,b.x)) return false;
        if(p.y<min(a.y,b.y)||p.y>max(a.y,b.y)) return false;
        return true;
    }
    return false;
}

// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z,
                          double a, double b, double c, double d)
{
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d)
{
    return fabs(cross(b-a, c-d)) < EPS;
}

bool LinesCollinear(PT a, PT b, PT c, PT d)
{
    return LinesParallel(a, b, c, d)
           && fabs(cross(a-b, a-c)) < EPS
           && fabs(cross(c-d, c-a)) < EPS;
}

// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d)
{
    if (LinesCollinear(a, b, c, d))
    {
        if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
                dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
        if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
            return false;
        return true;
    }
    if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
    if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
    return true;
}
// check if two lines are same
bool areLinesSame(PT a, PT b, PT c, PT d)
{
    if(fabs(cross(a-c,c-d))<EPS && fabs(cross(b-c,c-d))<EPS) return true;
    return false;
}
// check if two lines are parallel
bool areLinesParallel(PT a, PT b, PT c, PT d)
{
    if(fabs(cross(a-b,c-d))<EPS) return true;
    return false;
}

// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
/**
this sometimes does not work
//PT ComputeLineIntersection(PT a, PT b, PT c, PT d)
//{
//    b=b-a;
//    d=c-d;
//    c=c-a;
//    return a + b*cross(c, d)/cross(b, d);
//}
*/
PT ComputeLineIntersection(PT a, PT b, PT c, PT d)
{
    double a1,b1,c1,a2,b2,c2;
    a1 = a.y - b.y;
    b1 = b.x - a.x;
    c1 = cross(a, b);
    a2 = c.y - d.y;
    b2 = d.x - c.x;
    c2 = cross(c, d);
    double D = a1 * b2 - a2 * b1;
    return PT((b1 * c2 - b2 * c1) / D,(c1 * a2 - c2 * a1) / D);
}

// compute center of circle given three points
PT ComputeCircleCenter(PT a, PT b, PT c)
{
    b=(a+b)/2;
    c=(a+c)/2;
    return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}

// determine if point is in a possibly non-convex polygon (by William
// Randolph Franklin); returns 1 for strictly interior points, 0 for
// strictly exterior points, and 0 or 1 for the remaining points.
// Note that it is possible to convert this into an *exact* test using
// integer arithmetic by taking care of the division appropriately
// (making sure to deal with signs properly) and then by writing exact
// tests for checking point on polygon boundary
bool PointInPolygon(const vector<PT> &p, PT q)
{
    bool c = 0;
    int s=p.size();
    for (int i = 0,j=s-1; i < s; j=i++)
    {
        if ( ( (p[i].y > q.y) != (p[j].y > q.y ) ) &&
                (q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)))
            c = !c;
    }
    return c;
}

// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p, PT q)
{
    int s=p.size();
    for (int i = 0,j=s-1; i < s; j=i++)
        if (isPointOnSegment(q,p[j],p[i]))
            return true;
    return false;
}

// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r)
{
    vector<PT> ret;
    b = b-a;
    a = a-c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r*r;
    double D = B*B - A*C;
    if (D < -EPS) return ret;
    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}

// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
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

// This code computes the area or centroid of a (possibly non-convex)
// polygon, assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.  Note that the centroid is often known as
// the "center of gravity" or "center of mass".
double ComputeSignedArea(const vector<PT> &p)
{
    double area = 0;
    for(int i = 0; i < p.size(); i++)
    {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}

double ComputeArea(const vector<PT> &p)
{
    return fabs(ComputeSignedArea(p));
}

PT ComputeCentroid(const vector<PT> &p)
{
    PT c(0,0);
    double scale = 6.0 * ComputeSignedArea(p);
    for (int i = 0; i < p.size(); i++)
    {
        int j = (i+1) % p.size();
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
    }
    return c / scale;
}

// tests whether or not a given polygon (in CW or CCW order) is simple
bool IsSimple(const vector<PT> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        for (int k = i+1; k < p.size(); k++)
        {
            int j = (i+1) % p.size();
            int l = (k+1) % p.size();
            if (i == l || j == k) continue;
            if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
                return false;
        }
    }
    return true;
}
/**
Return a parallel line of line ab in counterclockwise
direction with d distance from ab
*/
pair<PT,PT> getParallelLine(PT a,PT b,double d)
{
    return mp(PointAlongLine(a,RotateCCW90(b-a)+a,d),PointAlongLine(b,RotateCW90(a-b)+b,d));
}

/**
Return a tangent line of line ab which intersects
with it at point c in counterclockwise direction
*/
pair<PT,PT> getTangentLine(PT a,PT b,PT c)
{
    return mp(RotateCCW90(a-c)+c,RotateCCW90(b-c)+c);
}

vector<PT> halfPlaneIntersection(const vector<PT> &poly, pair<PT,PT> ln)
{
    vector<PT> ret;
    int s=SZ(poly);
    for(int i=0;i<s;i++)
    {
        double c1=cross(ln.sc-ln.fs,poly[i]-ln.fs);
        double c2=cross(ln.sc-ln.fs,poly[(i+1)%s]-ln.fs);
        if(EQ(c1)>=0) ret.psb(poly[i]);
        if(EQ(c1*c2)<0)
        {
            if(!areLinesParallel(poly[i],poly[(i+1)%s],ln.fs,ln.sc))
            {
                ret.psb(ComputeLineIntersection(poly[i],poly[(i+1)%s],ln.fs,ln.sc));
            }
        }
    }
    return ret;
}

/*
void Test()
{

    // expected: (-5,2)
    cerr << RotateCCW90(PT(2,5)) << endl;

    // expected: (5,-2)
    cerr << RotateCW90(PT(2,5)) << endl;

    // expected: (-5,2)
    cerr << RotateCCW(PT(2,5),PI/2) << endl;

    // expected: (5,2)
    cerr << ProjectPointLine(PT(-5,-2), PT(10,4), PT(3,7)) << endl;

    // expected: (5,2) (7.5,3) (2.5,1)
    cerr << ProjectPointSegment(PT(-5,-2), PT(10,4), PT(3,7)) << " "
         << ProjectPointSegment(PT(7.5,3), PT(10,4), PT(3,7)) << " "
         << ProjectPointSegment(PT(-5,-2), PT(2.5,1), PT(3,7)) << endl;

    // expected: 6.78903
    cerr << DistancePointPlane(4,-4,3,2,-2,5,-8) << endl;

    // expected: 1 0 1
    cerr << LinesParallel(PT(1,1), PT(3,5), PT(2,1), PT(4,5)) << " "
         << LinesParallel(PT(1,1), PT(3,5), PT(2,0), PT(4,5)) << " "
         << LinesParallel(PT(1,1), PT(3,5), PT(5,9), PT(7,13)) << endl;

    // expected: 0 0 1
    cerr << LinesCollinear(PT(1,1), PT(3,5), PT(2,1), PT(4,5)) << " "
         << LinesCollinear(PT(1,1), PT(3,5), PT(2,0), PT(4,5)) << " "
         << LinesCollinear(PT(1,1), PT(3,5), PT(5,9), PT(7,13)) << endl;

    // expected: 1 1 1 0
    cerr << SegmentsIntersect(PT(0,0), PT(2,4), PT(3,1), PT(-1,3)) << " "
         << SegmentsIntersect(PT(0,0), PT(2,4), PT(4,3), PT(0,5)) << " "
         << SegmentsIntersect(PT(0,0), PT(2,4), PT(2,-1), PT(-2,1)) << " "
         << SegmentsIntersect(PT(0,0), PT(2,4), PT(5,5), PT(1,7)) << endl;

    // expected: (1,2)
    cerr << ComputeLineIntersection(PT(0,0), PT(2,4), PT(3,1), PT(-1,3)) << endl;

    // expected: (1,1)
    cerr << ComputeCircleCenter(PT(-3,4), PT(6,1), PT(4,5)) << endl;


    vector<PT> v;
    v.push_back(PT(0,0));
    v.push_back(PT(5,0));
    v.push_back(PT(5,5));
    v.push_back(PT(0,5));

    // expected: 1 1 1 0 0
    cerr << PointInPolygon(v, PT(2,2)) << " "
         << PointInPolygon(v, PT(2,0)) << " "
         << PointInPolygon(v, PT(0,2)) << " "
         << PointInPolygon(v, PT(5,2)) << " "
         << PointInPolygon(v, PT(2,5)) << endl;

    // expected: 0 1 1 1 1
    cerr << PointOnPolygon(v, PT(2,2)) << " "
         << PointOnPolygon(v, PT(2,0)) << " "
         << PointOnPolygon(v, PT(0,2)) << " "
         << PointOnPolygon(v, PT(5,2)) << " "
         << PointOnPolygon(v, PT(2,5)) << endl;

    // expected: (1,6)
    //           (5,4) (4,5)
    //           blank line
    //           (4,5) (5,4)
    //           blank line
    //           (4,5) (5,4)
    vector<PT> u = CircleLineIntersection(PT(0,6), PT(2,6), PT(1,1), 5);
    for (int i = 0; i < u.size(); i++) cerr << u[i],cerr << " ";
    cerr << endl;
    u = CircleLineIntersection(PT(0,9), PT(9,0), PT(1,1), 5);
    for (int i = 0; i < u.size(); i++) cerr << u[i],cerr << " ";
    cerr << endl;
    u = CircleCircleIntersection(PT(1,1), PT(10,10), 5, 5);
    for (int i = 0; i < u.size(); i++) cerr << u[i],cerr << " ";
    cerr << endl;
    u = CircleCircleIntersection(PT(1,1), PT(8,8), 5, 5);
    for (int i = 0; i < u.size(); i++) cerr << u[i],cerr << " ";
    cerr << endl;
    u = CircleCircleIntersection(PT(1,1), PT(4.5,4.5), 10, sqrt(2.0)/2.0);
    for (int i = 0; i < u.size(); i++) cerr << u[i],cerr << " ";
    cerr << endl;
    u = CircleCircleIntersection(PT(1,1), PT(4.5,4.5), 5, sqrt(2.0)/2.0);
    for (int i = 0; i < u.size(); i++) cerr << u[i],cerr << " ";
    cerr << endl;

    // area should be 5.0
    // centroid should be (1.1666666, 1.166666)
    PT pa[] = { PT(0,0), PT(5,0), PT(1,1), PT(0,5) };
    vector<PT> p(pa, pa+4);
    PT c = ComputeCentroid(p);
    cerr << "Area: " << ComputeArea(p) << endl;
    cerr << "Centroid: " << c << endl;


    PT a=PT(1.3,2.6), b=PT(8.1,13.7);
    double d=3.17096;
    PT r=PointAlongLine(a,b,d);
    deb(r.x,r.y);

    return ;
}
*/
/**
//////////////////////////////////////////////
line segment intersection for ll value
*/
/**
typedef pair<double,double> pdd;
struct PT
{
    ll x,y;
    PT(){}
    PT(ll x,ll y):x(x),y(y){}
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (double c)     const
    {
        return PT(x/c,   y/c  );
    }
};

PT MV(PT a,PT b){ PT r; r.x = b.x-a.x; r.y = b.y-a.y; return r;}
ll CV(PT a,PT b){return a.x*b.y - a.y*b.x;}

ll dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}
ll cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}
///***
bool areLinesSame(PT a, PT b, PT c, PT d)
{
    if(cross(a-c,c-d)==0 && cross(b-c,c-d)==0) return true;
    return false;
}
///***
bool areLinesParallel(PT a, PT b, PT c, PT d)
{
    if(cross(a-b,c-d)==0) return true;
    return false;
}

// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
//void ComputeLineIntersection(PT a, PT b, PT c, PT d,pdd &ret)
//{
//    b=b-a;
//    d=c-d;
//    c=c-a;
//    double h=(double)cross(c, d)/(double)cross(b, d);
//    ret.xx=(double) a.x + (double) b.x * h;
//    ret.yy=(double) a.y + (double) b.y * h;
//    return ;
//}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d,pdd &ret)
{
    double a1,b1,c1,a2,b2,c2;
    a1 = a.y - b.y;
    b1 = b.x - a.x;
    c1 = cross(a, b);
    a2 = c.y - d.y;
    b2 = d.x - c.x;
    c2 = cross(c, d);
    double D = a1 * b2 - a2 * b1;
    ret=mp((b1 * c2 - b2 * c1) / D,(c1 * a2 - c2 * a1) / D);
    return ret;
}

bool onsegment(PT a,PT b,PT c){
    return ( min(a.x,b.x)<=c.x && c.x<=max(a.x,b.x) && min(a.y,b.y)<=c.y && c.y<=max(a.y,b.y) ) ;
}
bool isSegmentIntersect(PT p1,PT p2,PT p3,PT p4)
{
    ll d1,d2,d3,d4;

    d1 = CV(MV(p3,p4),MV(p3,p1));
    d2 = CV(MV(p3,p4),MV(p3,p2));
    d3 = CV(MV(p1,p2),MV(p1,p3));
    d4 = CV(MV(p1,p2),MV(p1,p4));

    int s1,s2,s3,s4;
    s1=d1==0?0:d1<0?-1:1;
    s2=d2==0?0:d2<0?-1:1;
    s3=d3==0?0:d3<0?-1:1;
    s4=d4==0?0:d4<0?-1:1;

    if(s1*s2<0 && s3*s4<0)  return true;
    if(!d1 && onsegment(p3,p4,p1))  return true;
    if(!d2 && onsegment(p3,p4,p2))  return true;
    if(!d3 && onsegment(p1,p2,p3))  return true;
    if(!d4 && onsegment(p1,p2,p4))  return true;

    return false;
}
*/


int main()
{
    //Test();
    return 0;
}















