#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,f=0;
    cin>>t;
    while(t--){
        if(f){
            cout<<endl;
        }
        f=1;
        int n;
        cin>>n;
        string str[1100],qry;
        for(int i=0;i<n;i++){
            cin>>str[i];
        }
        while(cin>>qry && qry!="END"){
            string s1=qry;
            sort(s1.begin(),s1.end());
            printf("Anagrams for: %s\n",qry.c_str());
            int no=1;
            for(int i=0;i<n;i++){
                string s2=str[i];
                sort(s2.begin(),s2.end());
                if(s1==s2){
                    printf("%3d) %s\n",no,str[i].c_str());
                    no++;
                }
            }
            if(no==1){
                printf("No anagrams for: %s\n",qry.c_str());
            }
        }
    }
}
