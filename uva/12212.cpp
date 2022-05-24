#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int>num1,num2;
bool nonZero[50];

vector<int>makeNumberVector(ull x)
{
    vector<int>v;
    while(x){
	    v.push_back(x%10);
	    x/=10;
	}
	return v;
}

void makeEqualSizedVector(vector<int>&v1,vector<int>&v2)
{
    while(v1.size()<v2.size()) v1.push_back(0);
    while(v2.size()<v1.size()) v2.push_back(0);
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
}

ull dp[20][3][3][3][20][3][3];
bool vis[20][3][3][3][20][3][3];


ull solve(int pos,int small1,int small2,int leadingZero,int lastPos,int carry1,int carry2,int num)
{
    if(pos==num1.size()){

        if(((carry1 && lastPos>=0 && nonZero[lastPos]) || carry1==0) && ((carry2 && lastPos>=0) || carry2==0)){
//            cout<<num<<' '<<lastPos<<' '<<carry1<<' '<<carry2<<endl;
            return 1;
        }

        return 0;
    }
//    cout<<pos<<' '<<small1<<small2<<' '<<leadingZero<<' '<<lastPos<<' '<<carry1<<' '<<carry2<<endl;
    ull &ret=dp[pos][small1][small2][leadingZero][lastPos][carry1][carry2];
    bool &memo=vis[pos][small1][small2][leadingZero][lastPos][carry1][carry2];
    if(memo){
        return ret;
    }
    memo=true;
    ret=0;

    int st,en;
    if(small1){
        st=num1[pos];
    }else{
        st=0;
    }

    if(small2){
        en=num2[pos];
    }else{
        en=9;
    }

    int t1=0,t2=0;

    if(st==en){
//        cout<<st<<' '<<en<<' '<<num<<endl;
        if(!(leadingZero&(st==0))){
            if(st-carry1<num1[lastPos]){
                t1=1;
            }else{
                t1=0;
            }

            if(st>num2[lastPos]-carry2){
                t2=1;
            }else{
                t2=0;
            }
        }
//        cout<<t1<<' '<<t2<<' '<<num1[lastPos]<<' '<<num2[lastPos]<<endl;
        ret=solve(pos+1,small1,small2,leadingZero&(st==0),lastPos - !(leadingZero&(st==0)),t1,t2,num*10+st);
        return ret;
    }

    if(!(leadingZero&(st==0))){
        if(st-carry1<num1[lastPos]){
            t1=1;
        }else{
            t1=0;
        }
        if(st>num2[lastPos]-carry2){
                t2=1;
            }else{
                t2=0;
            }
    }
    ret+=solve(pos+1,small1,0,leadingZero&(st==0),lastPos - !(leadingZero&(st==0)),t1,t2,num*10+st);

    for(int i=st+1;i<=en-1;i++){
        if(!(leadingZero&(i==0))){
            if(i-carry1<num1[lastPos]){
                t1=1;
            }else{
                t1=0;
            }
            if(i>num2[lastPos]-carry2){
                t2=1;
            }else{
                t2=0;
            }
        }
        ret+=solve(pos+1,0,0,leadingZero&(i==0), lastPos - !(leadingZero&(i==0)),t1,t2,num*10+i);
    }
    if(!(leadingZero&(en==0))){
        if(en-carry1<num1[lastPos]){
            t1=1;
        }else{
            t1=0;
        }

        if(en>num2[lastPos]-carry2){
                t2=1;
            }else{
                t2=0;
            }
    }
    ret+=solve(pos+1,0,small2,leadingZero&(en==0), lastPos - !(leadingZero&(en==0)),t1,t2,num*10+en);
    return ret;
}


int main()
{
	ull a,b,x;
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++){
        cin>>a>>b;
        num1 = makeNumberVector(a);
        num2 = makeNumberVector(b);
        memset(nonZero,false,sizeof nonZero);
        if(num1.size()==num2.size()){
            nonZero[0]=true;
        }
        makeEqualSizedVector(num1,num2);
        for(int i=1;i<num1.size();i++){
            nonZero[i]=nonZero[i-1]|(num1[i]>0);
        }
//        memset(dp,-1,sizeof dp);
        memset(vis,false,sizeof vis);
        cout<<"Case "<<tc<<": "<<solve(0,1,1,1,num1.size()-1,0,0,0)<<endl;
	}
}
