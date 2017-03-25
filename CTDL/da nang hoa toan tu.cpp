#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
typedef struct Phan_So 
{
	int TU; 
	int MAU;
} PS;
int UCLN(PS C);
PS toigianPS(PS &A);
PS SetPS(int &T,int &M);
PS operator +(PS C1,PS C2);
PS operator -(PS C1,PS C2);
PS operator *(PS C1,PS C2);
PS operator /(PS C1,PS C2);
PS operator +(PS C1,int C2);
PS operator +(int C1,PS C2);
PS operator -(PS C1,int C2);
PS operator -(int C1,PS C2);
PS operator *(PS C1,int C2);
PS operator *(int C1,PS C2);
PS operator /(PS C1,int C2);
PS operator /(int C1,PS C2);
void DisplayPS(PS &A);
int main()
{
	PS ps1,ps2,ps3,ps4;
	int a,b,c,d;
	char tt;
	cout<<"Nhap phan so thu 1:"<<endl;
	cout<<"Nhap tu so: ";cin>>a;
	cout<<"Nhap mau so: ";cin>>b;
	cout<<"Nhap phan so thu 2:"<<endl;
	cout<<"Nhap tu so: ";cin>>c;
	cout<<"Nhap mau so: ";cin>>d;
	ps1= SetPS(a,b);
	ps2= SetPS(c,d);
	cout<<"Nhap vao phep toan muon thuc hien giua 2 phan so tren(+ - * /)"<<endl;
	cin>>tt;
	if(tt=='+')
	{
		ps3= ps1+ps2;
		cout<<"Tong cua 2 phan so tren la:"<<endl;
		DisplayPS(ps3);
	}
	if(tt== '-')
	{
		ps3= ps1-ps2;
		cout<<"Hieu cua 2 phan so tren la: "<<endl;
		DisplayPS(ps3);
	}
	if(tt=='*')
	{
		ps4=ps1*ps2;
		cout<<"Tich cua 2 phan so tren la:"<<endl;
		DisplayPS(ps4);
	}
	if(tt=='/')
	{
		ps4=ps1/ps2;
		cout<<"Thuong cua 2 phan so tren la:"<<endl;
		DisplayPS(ps4);
	}
	getch();
	return 0;
}
int UCLN(PS C)
{
	int A= C.MAU;
	int B= C.TU;
	while(A!=B)
	{
	if(A>B)
	A-=B;
	else B-=A;
	if(B==1) break;
    }
    return B;
}
PS toigianPS(PS &A)
{
	int m= UCLN(A);
	if(m!= 1)
	A.TU /=m;
	A.MAU /=m;
	return A;
}
PS SetPS(int &T,int &M)
{
	PS Temp;
	Temp.TU= T;
	Temp.MAU= M;
	return Temp;
}
PS operator +(PS C1,PS C2)
{
	PS tmp;
	tmp.TU=C1.TU*C2.MAU+C2.TU*C1.MAU;
	tmp.MAU= C1.MAU* C2.MAU;
	toigianPS(tmp);
	return tmp;
}
PS operator -(PS C1,PS C2)
{
	PS tmp;
	tmp.TU= C1.TU*C2.MAU-C2.TU*C1.MAU;
	tmp.MAU= C1.MAU*C2.MAU;
	toigianPS(tmp);
	return tmp;
}
PS operator *(PS C1,PS C2)
{
	PS tmp;
	tmp.TU= C1.TU*C2.TU;
	tmp.MAU= C1.MAU*C2.MAU;
	toigianPS(tmp);
	return tmp;
}
PS operator /(PS C1,PS C2)
{
	PS tmp;
	tmp.TU= C1.TU*C2.MAU;
	tmp.MAU= C1.MAU*C2.TU;
	toigianPS(tmp);
	return tmp;
}
PS operator +(PS C1,int C2)
{
	PS tmp;
	tmp.TU = C1.TU+C2*C1.MAU;
	tmp.MAU= C1.MAU;
	toigianPS(tmp);
	return tmp;
}
PS operator +(int C1,PS C2)
{
	PS tmp;
	tmp.TU= C1*C2.MAU+C2.TU;
	tmp.MAU= C2.MAU;
	toigianPS(tmp);
	return tmp;
}
PS operator -(PS C1,int C2)
{
	PS tmp;
	tmp.TU= C1.TU-C2*C1.MAU;
	tmp.MAU= C1.MAU;
	toigianPS(tmp);
	return tmp;
}
PS operator -(int C1,PS C2)
{
	PS tmp;
	tmp.TU= C1*C2.MAU- C2.TU;
	tmp.MAU= C2.MAU;
	toigianPS(tmp);
	return tmp;
}
PS operator *(PS C1,int C2)
{
	PS tmp;
	tmp.TU= C1.TU*C2;
	tmp.MAU= C1.MAU;
	toigianPS(tmp);
	return tmp;
}
PS operator *(int C1,PS C2)
{
	PS tmp;
	tmp.TU= C1*C2.TU;
	tmp.MAU= C2.MAU;
	toigianPS(tmp);
	return tmp;
}
PS operator /(PS C1,int C2)
{
	PS tmp;
	tmp.TU= C1.TU;
	tmp.MAU= C1.MAU*C2;
	toigianPS(tmp);
	return tmp;
}
PS operator /(int C1,PS C2)
{
	PS tmp;
	tmp.TU= C1*C2.MAU;
	tmp.MAU= C2.TU;
	toigianPS(tmp);
	return tmp;
}
void DisplayPS(PS &A)
{
	printf("%d/%d\n",A.TU,A.MAU);
}
