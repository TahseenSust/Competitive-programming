#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number
//The input to the function gauss is the system matrix a. The last column of this matrix is vector b.
int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}


int main()
{
    int x11,x12,y11,y12,x21,x22,y21,y22,t;

    cin>>t;
    cout<<"INTERSECTING LINES OUTPUT\n";
    while(t--){

        cin>>x11>>y11>>x12>>y12>>x21>>y21>>x22>>y22;

        vector<vector<double>>mat;
        vector<double>tmp,ans;

        tmp.push_back((y11-y12));
        tmp.push_back(-(x11-x12));
        tmp.push_back(-(y11*(x11-x12)-x11*(y11-y12)));
        mat.push_back(tmp);

        tmp.clear();

        tmp.push_back((y21-y22));
        tmp.push_back(-(x21-x22));
        tmp.push_back(-(y21*(x21-x22)-x21*(y21-y22)));
        mat.push_back(tmp);



        //cout<<(y11-y12)<<' '<<-(x11-x12)<<' '<<y11*(x11-x12)-x11*(y11-y12)<<endl;
        //cout<<(y21-y22)<<' '<<-(x21-x22)<<' '<<y21*(x21-x22)-x21*(y21-y22)<<endl;

        int sol=gauss(mat,ans);

        if(sol==0) cout<<"NONE\n";
        else if(sol==2) cout<<"LINE\n";
        else cout<<"POINT "<<setprecision(2)<<fixed<<ans[0]<<' '<<ans[1]<<endl;
    }
    cout<<"END OF OUTPUT\n";
}
