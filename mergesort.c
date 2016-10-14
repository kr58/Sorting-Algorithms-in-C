#include <stdio.h>

void merge(int *a,int l,int m,int r)
{
    int i,j,n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
 
    for(i=0;i<n1;i++) L[i]=a[l+i];
    for(j=0;j<n2;j++) R[j]=a[m+1+j];

    i=j=0;
    while(i<n1 && j<n2)
        if (L[i]<R[j]) a[l++]=L[i++];
        else a[l++]=R[j++];

    while(i<n1) a[l++]=L[i++];
    while(j<n2) a[l++]=R[j++];
}
 
void msort(int *a,int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        msort(a,l,m);
        msort(a,m+1,r);
        merge(a,l,m,r);
    }
}


void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n\n");
}
int main()
{
	int t,i,a[]={2,5,32,5,6,4,3,32,324,5,123},n=11;
	print(a,n);
	msort(a,0,n);
	print(a,n);
}