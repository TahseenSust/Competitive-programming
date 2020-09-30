#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

typedef long long ll;

bool check(int mask,int pos)
{
    return mask&(1<<pos);
}

int SET(int mask,int pos)
{
    return mask|(1<<pos);
}

int FLIP(int mask,int pos)
{
    return mask^(1<<pos);
}

int reset(int mask,int pos){return mask&~(1 << pos);}



int main()
{

}
