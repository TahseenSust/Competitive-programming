#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
double dhal(double x1,double y1,double x2,double y2)
{
    if(x2-x1==0) return (double)INF;
    return (double)(y2-y1)/(double)(x2-x1);
}

double distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    double x[5],y[5];
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        for(int i=1;i<=4;i++){
            cin>>x[i]>>y[i];
        }
        printf("Case %d: ",tc);
        if(abs(dhal(x[1],y[1],x[2],y[2])-dhal(x[3],y[3],x[4],y[4]))<=0.00001){

            if(abs(distance(x[1],y[1],x[2],y[2])-distance(x[3],y[3],x[4],y[4]))<=0.00001){

                double a=distance(x[1],y[1],x[2],y[2]),b,c=distance(x[3],y[3],x[4],y[4]),d,k1,k2;

                if(abs(dhal(x[1],y[1],x[3],y[3])-dhal(x[2],y[2],x[4],y[4]))<=0.00001){
                    b=distance(x[1],y[1],x[3],y[3]);
                    d=distance(x[2],y[2],x[4],y[4]);
                    k1=distance(x[1],y[1],x[4],y[4]);
                    k2=distance(x[2],y[2],x[3],y[3]);
                }else if(abs(dhal(x[1],y[1],x[4],y[4])-dhal(x[2],y[2],x[3],y[3]))<=0.00001){
                    b=distance(x[1],y[1],x[4],y[4]);
                    d=distance(x[2],y[2],x[3],y[3]);
                    k1=distance(x[1],y[1],x[3],y[3]);
                    k2=distance(x[2],y[2],x[4],y[4]);
                }

                if(abs(a-b)<=0.00001 && abs(b-c)<=0.00001 && abs(c-d)<=0.00001){
                    if(abs(k1-k2)<=0.00001){
                        cout<<"Square\n";
                    }else{
                        cout<<"Rhombus\n";
                    }
                }else{
                    if(abs(k1-k2)<=0.00001){
                        cout<<"Rectangle\n";
                    }else{
                        cout<<"Parallelogram\n";
                    }
                }
            }else{
                cout<<"Trapezium\n";
            }
        }else if(abs(dhal(x[1],y[1],x[3],y[3])-dhal(x[2],y[2],x[4],y[4]))<=0.00001){

            if(abs(distance(x[1],y[1],x[3],y[3])-distance(x[2],y[2],x[4],y[4]))<=0.00001){

                double a=distance(x[1],y[1],x[3],y[3]),b,c=distance(x[2],y[2],x[4],y[4]),d,k1,k2;

                if(abs(dhal(x[1],y[1],x[2],y[2])-dhal(x[3],y[3],x[4],y[4]))<=0.00001){
                    b=distance(x[1],y[1],x[2],y[2]);
                    d=distance(x[3],y[3],x[4],y[4]);
                    k1=distance(x[1],y[1],x[4],y[4]);
                    k2=distance(x[2],y[2],x[3],y[3]);

                }else if(abs(dhal(x[1],y[1],x[4],y[4])-dhal(x[2],y[2],x[3],y[3]))<=0.00001){
                    b=distance(x[1],y[1],x[4],y[4]);
                    d=distance(x[2],y[2],x[3],y[3]);
                    k1=distance(x[1],y[1],x[2],y[2]);
                    k2=distance(x[3],y[3],x[4],y[4]);
                }
                //cout<<dhal(x[1],y[1],x[4],y[4])<<' '<<dhal(x[2],y[2],x[3],y[3])<<endl;
                //cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
                if(abs(a-b)<=0.00001 && abs(b-c)<=0.00001 && abs(c-d)<=0.00001){
                    if(abs(k1-k2)<=0.00001){
                        cout<<"Square\n";
                    }else{
                        cout<<"Rhombus\n";
                    }
                }else{
                    if(abs(k1-k2)<=0.00001){
                        cout<<"Rectangle\n";
                    }else{
                        cout<<"Parallelogram\n";
                    }
                }
            }else{
                cout<<"Trapezium\n";
            }
        }else if(abs(dhal(x[1],y[1],x[4],y[4])-dhal(x[2],y[2],x[3],y[3]))<=0.00001){
            if(abs(distance(x[1],y[1],x[4],y[4])-distance(x[2],y[2],x[3],y[3]))<=0.00001){
                double a=distance(x[1],y[1],x[4],y[4]),b,c=distance(x[2],y[2],x[3],y[3]),d,k1,k2;
                if(abs(dhal(x[1],y[1],x[2],y[2])-dhal(x[3],y[3],x[4],y[4]))<=0.00001){
                    b=distance(x[1],y[1],x[2],y[2]);
                    d=distance(x[3],y[3],x[4],y[4]);
                    k1=distance(x[1],y[1],x[3],y[3]);
                    k2=distance(x[4],y[4],x[2],y[2]);
                }else if(abs(dhal(x[1],y[1],x[3],y[3])-dhal(x[4],y[4],x[2],y[2]))<=0.00001){
                    b=distance(x[1],y[1],x[3],y[3]);
                    d=distance(x[4],y[4],x[2],y[2]);
                    k1=distance(x[1],y[1],x[2],y[2]);
                    k2=distance(x[3],y[3],x[4],y[4]);
                }
                if(abs(a-b)<=0.00001 && abs(b-c)<=0.00001 && abs(c-d)<=0.00001){
                    if(abs(k1-k2)<=0.00001){
                        cout<<"Square\n";
                    }else{
                        cout<<"Rhombus\n";
                    }
                }else{
                    if(abs(k1-k2)<=0.00001){
                        cout<<"Rectangle\n";
                    }else{
                        cout<<"Parallelogram\n";
                    }
                }
            }else{
                cout<<"Trapezium\n";
            }
        }else{
            cout<<"Ordinary Quadrilateral\n";
        }
    }
}

