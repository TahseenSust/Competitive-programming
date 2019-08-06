#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, k = 0, j, sum = 1;
    long ara[100];
    while(cin>>ara[i] && ara[i]){
        i++;
    }
    cout << "PERFECTION OUTPUT" << endl;
    for(;k < i; k++) {
        sum = 1;
        printf("%5d ",ara[k]);
        for(j = 2; j <= sqrt(ara[k]); j++) {
            if(ara[k] % j == 0) {
                sum += ( j == ara[k]/j ? j : j + (ara[k]/j) );
            }
        }
        if(sum < ara[k] || ara[k] == 1) {
            cout << "DEFICIENT" << endl;
        }
        else if(sum > ara[k]) {
            cout << "ABUNDANT" << endl;
        }
        else {
            cout << "PERFECT" << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}

