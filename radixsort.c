#include <stdio.h>

void print(int *a,int n)
{
	int i=0;
	while(i<n) 
		printf("%d ",a[i++]);
	printf("\n");
}

void rasort(int *a,int *b,int n,int d)
{
	int c[10]={0},i;
	for(i=0;i<n;i++)
		c[(a[i]/d)%10]++;
	for(i=1;i<10;i++)
		c[i]+=c[i-1];
	for(i=n-1;i>=0;i--)
	{
		b[c[(a[i]/d)%10]-1]=a[i];
		c[(a[i]/d)%10]--;
	}
	if(d<1000) rasort(b,a,n,d*10);
}

int main()
{
	int a[]={56,361,34,123,5,764,22,991},b[8],n=8;
	print(a,n);
	rasort(a,b,n,1);
	print(b,n);
}