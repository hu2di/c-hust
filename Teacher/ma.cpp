#include<stdio.h>
#include<conio.h>
int ktra(int Mx,int My,int Dx,int Dy);
int main()
{
    int Mx,My,Dx,Dy;
    printf("Nhap toa do ma:\n");
    printf("Mx = ");
    scanf("%d",&Mx);
    printf("My = ");
    scanf("%d",&My);
    printf("Nhap toa do diem D:\n");
    printf("Dx = ");
    scanf("%d",&Dx);
    printf("Dy = ");
    scanf("%d",&Dy);
    if (ktra(Mx,My,Dx,Dy)==1) printf("Con ma co the di den D!");
    else printf("Con ma khong the di den D!");
    return 0;
}
int ktra(int Mx,int My,int Dx,int Dy)
{
    if ((Mx==Dx)&&(My==Dy))return 1;
    if ((Mx>8)||(My>8)||(Mx<1)||(My<1)) return 0;
    return (ktra(Mx-1,My-2,Dx,Dy));
    return (ktra(Mx-2,My-1,Dx,Dy));
    return (ktra(Mx-1,My+2,Dx,Dy));
    return (ktra(Mx+2,My-1,Dx,Dy));
    return (ktra(Mx+1,My+2,Dx,Dy));
    return (ktra(Mx+2,My+1,Dx,Dy));
    return (ktra(Mx+1,My-2,Dx,Dy));
    return (ktra(Mx-2,My+1,Dx,Dy));
}

