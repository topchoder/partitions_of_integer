#include <bits/stdc++.h>
using namespace std;

struct node
{
    int a;
    node *next;
};

node *nuget(int x)
{
	node *nu=new node;
    nu->a=x;
    nu->next=NULL;
    return nu;
}

void coutin(node *root)
{
	while(root)
	{
		cout<<root->a<<" ";
		root=root->next;
	}
	cout<<"\n";
	return;
}

void comblist(int sum,int x,node **root,int n)
{
	if(!sum)//print current list
	{
		coutin(*root);
		return;
	}
	for(int i=x;i<=n;i++)
	{
		if(*root==NULL&&sum>=i)
		{
			*root=nuget(i);
      comblist(sum-i,i,root,n);
      *root=NULL;//backtracking for new list
		}
		else if(*root&&sum>=i)
		{
			node *tem=(*root);
			while(tem->next)
			{
				tem=tem->next;
			}
			tem->next=nuget(i);
      comblist(sum-i,i,root,n);
      while(tem->next->next)
      {
          tem=tem->next;
      }
      node *tem1=tem->next;
      tem->next=tem1->next;
		}
	}     	
}

signed main()
{
   	int sum=6;
    node *root=NULL;
    comblist(sum,1,&root,sum);
	  return 0;
}
