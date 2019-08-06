// Rumman vai

#include<bits/stdc++.h>
using namespace std;

struct data
{
    int tree[10];
    int complete;
}trie[100001];
 
string text;
 
int tot_node=0;
 
void Insert_trie(int node,int ind)
{
    if(text[ind]=='\0')
    {
        trie[node].complete=1;
        return;
    }
    int id=(int) (text[ind]-'0');
    if(trie[node].tree[id]==-1) trie[node].tree[id]=++tot_node;
    int nnode=trie[node].tree[id];
    Insert_trie(nnode,ind+1);
}

bool Search_Trie(int node,int ind)
{
	if(text[ind]=='\0')
	{
		return trie[node].complete;
	}
	int id=(int) (text[ind]-'0');
    if(trie[node].tree[id]==-1) return false;
    int nnode=trie[node].tree[id];
    return Search_Trie(nnode,ind+1);
}

int main(int argc, char const *argv[])
{
	memset(trie,-1,sizeof trie);
	text="0154";
	Insert_trie(0,0);
	text="0153";
	Insert_trie(0,0);
	text="0152";
	Insert_trie(0,0);
	text="0155";
	cout<<Search_Trie(0,0)<<endl;
	return 0;
}
