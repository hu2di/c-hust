#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define TRUE 1
#define FALSE 0
typedef int Matran[2000];
Matran data;
int n;
int x,y,i,j,m,k;
int that,tim;
//Nhap cac phan tu can sap xep
void Nhapdl()
{
    int i=0;
    printf("\nNhap vao so phan tu can sap xep:");
    scanf("%d",&n);
    printf("\nCac phan tu cau day:\n");
    for (i=0;i<n;i++)
    {
        data[i]=srand(1000);
        printf("%d",data[i]);
    }
    return 0;
}
//In ket qua ra man hinh
void Inkq()
{
    int i;
    printf("\nDay da sap xep:\n");
    for (i=0;i<n;i++)
    printf("%d",data[i]);
    return 0;
}
//Tim kiem mot phan tu trong day da sap xep
int BinarySearch(int y)
{
    int l,j,r,tim;
    l=0;
    r=n-1;
    tim=FALSE;
    while(l<r)
    {
        j=(l+r)/2;
        if (data[j]<y) l=j+1;
        else
        if (data[j]>y) r=j-1;
        else
        {
            tim=TRUE;
            return 1;
        }
    }
    return 0;
}
//QuickSort
void QuickSort(const int l,const int r)
{
    int w;
    if (l>=r) return 0;
    else
    if (r==l+1)
    {
        if (data[l]>data[r])
        {
            w=data[l];
            data[l]=data[r];
            data[r]=w;
        }
        return 0;
    }
    i=l+1;
    j=r;
    y=data[l];
    do
    {
        while ((i<r)&&(data[i]<=y)) i++;
        while ((j>l)&&(data[j]>=y)) j--;
        if (i<j)
        {
            w=data[i];
            data[i]=data[j];
            data[j]=w;
            i++;
            j--;
        }
    } while (i<j);
    data[l]=data[j];
    data[j]=y;
    if (j>1) QuickSort(l,j-1);
    QuickSort(j+1,r);
    return 0;
}
//BulleSort
void BulleSort()
{
    for (i=1;i<n;i++)
    for (j=n-1;j>=i;j--)
    if (data[j-1]>data[j])
    {
        x=data[j-1];
        data[j-1]=data[j];
        data[j]=x;
    }
    return 0;
}
int main()
{
	char ch;
	int daxep=0;
	do
	{
	    printf("\n                  Sap xep va tim kiem tren mang\n");
	    printf("\n                        1.Nhap du lieu");
	    printf("\n                        2.Sap xep QuickSort");
	    printf("\n                        3.Sap xep BulleSort");
	    printf("\n                        4.Tim kiem");
	    printf("\n                        5.Thoat");
	    printf("\n\n                        Lua chon:");
	    ch=getch();
	    switch(ch)
	    {
	        case '1':
	        Nhapdl();
	        daxep=0;
	        getch();
	        break;
	        case '2':
	        if (!daxep) QuickSort(0,n-1);
	        Inkq();
	        getch();
	        daxep=1;
	        break;
	        case '3':
	        if (!daxep) BulleSort();
	        Inkq;
	        getch();
	        daxep=1;
	        break;
	        case '4':
	        if (!daxep) break;
	        Inkq();
	        printf("\nPhan tu can tim:");
	        scanf("%d",&y);
	        if (BinarySearch(y)==0) printf("\nKhong co trong day!");
	        else printf("\nCo trong day!");
	        getch();
	        break;
	        case '5':
	        exit(1);
	    }
	} while (1);
}
