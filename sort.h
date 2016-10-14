void bubsort(int a[],int n)
{
   int i,j,t;
   for(i=0;i<n-1;i++)
      for(j=0;j<n-i-1;j++)
         if(a[j]>a[j+1])
         {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
         }
}

void selsort(int a[];int n)
{
   int i,j,loc,t;
   for(i=0;i<n-1;i++)
   {
      loc=i;
      for(j=i;j<n;j++)
         if(a[loc]>a[j])
            loc=j;
      t=a[i];
      a[i]=a[loc];
      a[loc]=t;
   }
}

void insort(int a[],int n)
{
   int i,j,key;
   for(j=1;j<n;j++)
   {
      key=a[j];
      i=j-1;
      while(a[i]>key && i>=0)
         a[i+1]=a[i--];
      a[i+1]=key;
   }
}
