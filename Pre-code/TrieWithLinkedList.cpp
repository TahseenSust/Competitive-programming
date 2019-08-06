#include<bits/stdc++.h>
using namespace std;

struct node
{
	bool endmark;
	node* next[30];
	node()
	{
		endmark=0;
		for(int i=0;i<30;i++){
			next[i]=NULL;
		}
	}
}*root;

void Insert(string str)
{
	node* cur=root;
	for(int i=0;i<str.size();i++){
		int id=str[i]-'0';
		if(cur->next[id]==NULL){
			cur->next[id]=new node();
		}
		cur=cur->next[id];
	}
	cur->endmark=true;
}

bool Search(string str)
{
	node* cur=root;
	for(int i=0;i<str.size();i++){
		int id=str[i]-'0';
		if(cur->next[id]==NULL){
			return false;
		}
		cur=cur->next[id];
	}
	return cur->endmark;
}

void del(node* cur=root)
{
	for(int i=0;i<30;i++){
		if(cur->next[i])
			del(cur->next[i]);
	}
	delete(cur);
}

int main()
{
	root=new node();
	del();
}
