#include<stdio.h>
int main()
{
	printf("Hello");
	return 0;
}

//Xây dựng hàm tìm kiếm nhị phân trên mảng
int BinarySearch(int a[],int n,int x)
{
int left=0,right=n-1;
int mid;
do
{
       mid=(left+right)/2;
if(X==a[mid])
break;
else if (x<a[mid]) right=mid-1;
else left =mid+1;
}
while(left <= right)

return mid;
else return -1;//không tìm thấy X
}
