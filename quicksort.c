#include <stdio.h>

int part(int *a,int p,int r)
{
	int i=p,j; int t;
	for(j=p;j<r;j++)
		if(a[j]<=a[r])
		{
			t=a[i]; a[i]=a[j]; a[j]=t;
			i++;
		}
	t=a[i]; a[i]=a[r]; a[r]=t;
	return i;
}

void qsort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=part(a,p,r);
		qsort(a,p,q-1);
		qsort(a,q+1,r);
	}
}

void print(int *a,int p,int r)
{
	for(;p<=r;p++)
		printf("%d ",a[p]);
	printf("\n\n");
}

int main()
{
	int a[]={2,1,4,2,7},n=5;
	print(a,0,n-1);
	qsort(a,0,n-1);
	print(a,0,n-1);
}