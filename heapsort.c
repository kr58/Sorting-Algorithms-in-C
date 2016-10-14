#include <stdio.h>
#define left(i) 2*i
#define right(i) 2*i+1

void heapify(int *a,int n,int i)
{
	int t; int l=left(i),r=right(i),max=i; 
	
	if(l<=n && a[l]>a[max]) max=l;
	if(r<=n && a[r]>a[max]) max=r;

	if(max!=i)
	{
		t=a[i]; a[i]=a[max]; a[max]=t;
		heapify(a,n,max);
	}
}

void buildheap(int *a,int n)
{ int i; for(i=n/2;i>=1;i--) heapify(a,n,i); }

void hsort(int *a,int n)
{

	int i,t; buildheap(a,n);
	for(i=n;i>=1;i--)
	{
		t=a[i]; a[i]=a[1]; a[1]=t;
		heapify(a,--n,1);
	}
}

void print(int *a,int n)
{
	int i,c=1;
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
		//if(i==c){ c=right(c); printf("\n"); }
	}printf("\n\n");
}

int main()
{
	int a[]={-1,2,1,4,2,7},n=5;
	// heaping starts from index 1 so a[0] is a dumb value
	print(a,n);
	hsort(a,n);
	print(a,n);
}