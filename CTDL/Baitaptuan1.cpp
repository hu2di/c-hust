 #include<stdio.h>
#include<conio.h>
int main()
{
int A=10,B;
double x,y=5.0;
int *pA,*pB;
double *px,**py;
pA=&B;
pB=&A;
*pA= A+ *pB * 2;
px=&x;
*py=px;
x= y+ *pA;
**py=*px+ y/2;
printf("kich thuoc cua pA la %d \n",sizeof(pA));
printf("kich thuoc cua pB la %d \n",sizeof(pB));
printf("kich thuoc cua px la %d \n",sizeof(px));
printf("kich thuoc cua py la %d \n",sizeof(py));
printf("gia tri pA la %x \n",pA);
printf("gia tri pB la %x \n",pB);
printf("gia tri px la %x \n",px);
printf("gia tri py la %x \n",py);
printf("gia tri A la %d \n",A);
printf("gia tri B la %d \n",B);
printf("gia tri x la %f \n",x);
printf("gia tri y la %f \n",y);
getch();
return 0;
}

