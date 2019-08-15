#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


bool solve(int sum,int mask1,int mask2,int mask3,int mask4,int mask5,int mask6)
{
    //cout<<sum<<endl;
    if(mask1<(1<<4)-1 && sum+1<=31 && solve(sum+1,(mask1<<1)|1,mask2,mask3,mask4,mask5,mask6)==0) return 1;
    if(mask2<(1<<4)-1 && sum+2<=31 && solve(sum+2,mask1,(mask2<<1)|1,mask3,mask4,mask5,mask6)==0) return 1;
    if(mask3<(1<<4)-1 && sum+3<=31 && solve(sum+3,mask1,mask2,(mask3<<1)|1,mask4,mask5,mask6)==0) return 1;
    if(mask4<(1<<4)-1 && sum+4<=31 && solve(sum+4,mask1,mask2,mask3,(mask4<<1)|1,mask5,mask6)==0) return 1;
    if(mask5<(1<<4)-1 && sum+5<=31 && solve(sum+5,mask1,mask2,mask3,mask4,(mask5<<1)|1,mask6)==0) return 1;
    if(mask6<(1<<4)-1 && sum+6<=31 && solve(sum+6,mask1,mask2,mask3,mask4,mask5,(mask6<<1)|1)==0) return 1;

    return 0;


}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string str;


    while(cin>>str){

        int sum=0,mask[14]={0};

        for(int i=0;i<str.size();i++)
        {
            int num=str[i]-'0';
            sum+=num;
            mask[num-1]=(mask[num-1]<<1)|1;
        }

        bool state=solve(sum,mask[0],mask[1],mask[2],mask[3],mask[4],mask[5]);

        if((str.size()%2==0 && state) || (str.size()%2==1 && !state)){
            cout<<str<<" A\n";
        }else{
            cout<<str<<" B\n";
        }
    }

}
