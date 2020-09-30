/*
ID: tahseen1
LANG: C++
TASK: friday
*/
#include<bits/stdc++.h>
bool isleap(int n)
{
    if(n%400==0||(n%4==0&&(n%100))){
        return true;
    }else{
        return false;
    }
}
void setmonth(int month[])
{
    month[0]=31;
    month[1]=28;
    month[2]=31;
    month[3]=30;
    month[4]=31;
    month[5]=30;
    month[6]=31;
    month[7]=31;
    month[8]=30;
    month[9]=31;
    month[10]=30;
    month[11]=31;
}
int week[20];
using namespace std;
int main()
{
    ofstream fcout("friday.out");
    ifstream fcin("friday.in");
    int year=1900,n,month[12],w=2;
    bool leap;
    setmonth(month);
    while(fcin>>n){
        year=1900,w=2;
        memset(week,0,sizeof(week));
        for(int i=year;i<=year+n-1;i++){
            if(isleap(i)){
                month[1]=29;
            }else{
                month[1]=28;
            }
            for(int j=0;j<12;j++){
                for(int d=1;d<=month[j];d++){
                    w++;
                    if(d==13){
                        week[w]++;
                    }
                    if(w==7){
                        w=0;
                    }
                }
            }
        }
        fcout<<week[1];
        for(int i=2;i<=7;i++){
            fcout<<' '<<week[i];
        }
        fcout<<endl;
    }
}
