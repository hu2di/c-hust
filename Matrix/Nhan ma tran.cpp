#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
int Capphat(int** &A,int M,int N);
void NhapMT(int** &A,int M,int N,char Sbol);
void Giaiphong(int** &Mt);
void Hienthi(int** &A,int M,int N);
void NhanMT(int** &A,int** &B,int** &C,int M,int N,int P,int Q);
int main()
{
	int M,N,P,Q;
	int **A= NULL,**B=NULL,**C=NULL;
	cout<<"Nhap so hang cua ma tran thu nhat"<<endl;
	cin>>M;
	cout<<endl<<"Nhap so cot cua ma tran thu nhat"<<endl;
	cin>>N;
	cout<<"Nhap so hang cua ma tran thu 2:"<<endl;
	cin>>P;
	cout<<"Nhap so cot ma tran thu 2:"<<endl;
	cin>>Q;
	if(N!=P)
	{
		cout<<"Hai ma tran khong the nhan voi nhau"<<endl;
	}
	else
	{
	if(Capphat(A,M,N))
	{
		cout<<"Khong du bo nho"<<endl;
		return 1;
	}
	if(Capphat(B,P,Q))
	{
		cout<<"Khong du bo nho"<<endl;
		Giaiphong(A);
		return 1;
		
	}
	if(Capphat(C,M,Q))
	{
		cout<<"Khong du bo nho"<<endl;
		Giaiphong(A);
		Giaiphong(B);
		return 1;
	}
	//Nhap ma tran
	cout<<"Nhap ma tran thu 1:"<<endl;
	NhapMT(A,M,N,'A');
	cout<<"Nhap ma tran thu 2:"<<endl;
	NhapMT(B,P,Q,'B');
	
	cout<<"Ma tran thu 1:"<<endl;
	Hienthi(A,M,N);
	cout<<"Ma tran thu 2:"<<endl;
	Hienthi(B,P,Q);
	NhanMT(A,B,C,M,N,P,Q);
	cout<<"Tich cua 2 ma tran la:"<<endl;
	Hienthi(C,M,Q);
	Giaiphong(A);
	Giaiphong(B);
	Giaiphong(C);
    }
    getch();
    return 0;
    
}
int Capphat(int** &A,int M,int N)
{
	int i,j;
	A= new int *[M];
	int *temp= new int [M*N];
	for(i=0;i<M;i++)
	{
		A[i]= temp;
		temp += N;
	}
	return 0;
}
void Giaiphong(int** &Mt)
{
	if(Mt != NULL)
	delete[]Mt[0];
	delete[]Mt;
}
void NhapMT(int** &A,int M,int N,char Sbol)
{
	int i,j;
	for(i=0;i<M;i++)
	for(j=0;j<N;j++)
	{
		cout<<Sbol<<"["<<i<<"]["<<j<<"]= ";cin>> A[i][j];
	}
}
void Hienthi(int** &A,int M,int N)
{
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<A[i][j]<<"  ";
		}
		cout<<endl;
	}
}
void NhanMT(int** &A,int** &B,int** &C,int M,int N,int P,int Q)
{
	int k=0;
	for(int i=0;i<M;i++)
	for(int j=0;j<Q;j++)
	{
		C[i][j]=0;
	for(k=0;k<N;k++)
	C[i][j]+=A[i][k]*B[k][j];
	}
}
