#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n][n];
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    int max=0;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    if (abs(a[i][j])>=max) max=abs(a[i][j]);
	for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
        if (abs(a[i][j])== max) printf("%d %d %d \n",a[i][j],i,j);
    }
	return 0;
}
