#include<bits/stdc++.h>
using namespace std;
struct data
{
    int tree[28];
    int complete;
}trie[500001];
char text[25];
int tot_node=1;
void Insert_trie()
{
    int node=0;
    for(int i=0;text[i];i++){
        int id=(int) (text[i]-'a');
        if(trie[node].tree[id]==0){
            trie[node].tree[id]=++tot_node;
        }
        node=trie[node].tree[id];
    }
    trie[node].complete++;
}
int Search_Trie()
{
    int node=1;
	for(int i=0;text[i];i++){
        int id=(int) (text[i]-'a');
        if(trie[node].tree[id]==0) return 0;
        node=trie[node].tree[id];
	}
	return trie[node].complete;
}

int main(int argc, char const *argv[])
{
	
}
