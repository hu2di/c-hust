#include<stdio.h>
#include<math.h>
int ngto(int n);
int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int sum=0;
    for (int i=m;i<=n;i++)
    {
        if (ngto(i)==1)
        sum=sum+i;
    }
    printf("%d",sum);
	return 0;
}
int ngto(int n)
{
    if (n==1) return 0;
    int i;
    for (i=2;i<=sqrt(n);i++)
    if ((n % i)==0) return 0;
    return 1;
}
