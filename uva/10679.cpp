#include<bits/stdc++.h>
using namespace std;
const int N=1005;

#define vi vector<int>
#define eb emplace_back

struct aho_corasick
{
    bool is_end[N];
    int link[N]; ///A suffix link for a vertex p is a edge that points to the longest proper suffix of the string corresponding to the vertex p.
    int psz; ///tracks node numbers of the trie
    map<char, int> to[N]; ///tracks the next node
    vi ending[N]; ///ending[i] stores the indexes of patterns which ends at node i(from the trie)
    vi oc[N]; ///oc[i] stores ending index of all occurrences of pattern[i] so real oc[i][j]=oc[i][j]-pattern[i].size()+1,0-indexed
    int cnt[N],path[N],ind[N],len;///for number of occurrences
    void clear()
    {
        for(int i = 0; i < psz; i++)
            is_end[i] = 0,cnt[i]=0,path[i]=0, ind[i]=0,link[i] = 0, to[i].clear(),ending[i].clear(),oc[i].clear();
        psz = 1;
        is_end[0] = 1;
        len=0;
    }
    aho_corasick()
    {
        psz = N - 2;
        clear();
    }
    void add_word(string s,int idx)
    {
        int u = 0;
        for(char c: s)
        {
            if(!to[u].count(c))
                to[u][c] = psz++;
            u = to[u][c];
        }
        is_end[u] = 1;
        ending[u].eb(idx);
        ind[idx]=u;
    }
    void populate(int cur) /// merging the occurrences of patterns ending at cur node in the trie
    {
        for(auto occ: ending[link[cur]])
            ending[cur].eb(occ);
    }
    void push_links()
    {
        queue<int> q;
        int u, v, j;
        char c;
        q.push(0);
        link[0] = -1;
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            for(auto it: to[u])
            {
                v = it.second;
                c = it.first;
                j = link[u];
                while(j != -1 && !to[j].count(c))
                    j = link[j];
                if(j != -1)
                    link[v] = to[j][c];
                else
                    link[v] = 0;
                q.push(v);
                populate(v);
                path[len++]=v;
            }
        }
    }
    void populate(vi &en, int cur)/// occurrences of patterns in the given string
    {
        for(auto idx: en)
        {
            oc[idx].eb(cur);
        }
    }
    void traverse(string s)
    {
        int n=s.size();
        int cur=0;///root
        for(int i=0; i<n; i++)
        {
            char c=s[i];
            while(cur!=-1 && !to[cur].count(c))
                cur=link[cur];
            if(cur!=-1)
                cur=to[cur][c];
            else
                cur=0;
            populate(ending[cur],i);
            cnt[cur]++;
        }
        for(int i=len-1; i>=0; i--)
            cnt[link[path[i]]]+=cnt[path[i]];
    }
};
aho_corasick t;
string p[N];
int main()
{
    int i,j,k,n,m,tc;
    cin>>tc;

    while(tc--){
        string s;
        cin>>s;
        cin>>m;
        for(i=0; i<m; i++)
        {
            cin>>p[i];
            t.add_word(p[i],i);
        }
        t.push_links();
        t.traverse(s);
        for(i=0; i<m; i++){
            if(t.cnt[t.ind[i]]){
                cout<<"y\n";
            }else{
                cout<<"n\n";
            }
        }
        t.clear();
    }
    return 0;
}
