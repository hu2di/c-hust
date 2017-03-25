#include<stdio.h>
#include<math.h>
int main()
{   long long i,n=0;
    do
    {
    printf("Nhap n=");
	scanf("%dll",&n);
	}
	while (n<=0);
	for (i=2;i<=sqrt(n);i++)
		if ((n%i)==0)
		{
			printf("Khong nguyen to");
			return 0;
		}
	printf("Nguyen to");
	return 0;
}
