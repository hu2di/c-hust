#include<iostream>
#include<conio.h>
using namespace std;

float nhap_mt(float *A,int m,int n,char c);
float cong_mt(float *A,float *B,int m,int n);
float tru_mt(float *A,float *B,int m,int n);
float nhan_mt(float *A,float *B,int m,int n);

int main(){
	float *A=NULL,*B=NULL;
	int m,n;
	cout<<" _____________ \n | Bai tap 2 | \n _____________ \n \n Nhap so hang: "; cin>>m;
	cout<<"\n Nhap so cot: ";  cin>>n;
	A=new float[m*n];
	B=new float[m*n];
	cout<<"\n Nhap ma tran 1: "<<endl;
	nhap_mt(A,m,n,'A');
	cout<<"\n Nhap ma tran 2: "<<endl;
	nhap_mt(B,m,n,'B');
	cout<<"\n Tong hai ma tran ! "<<endl;
	cong_mt(A,B,m,n);
	cout<<"\n Hieu hai ma tran 1-2 !"<<endl;
	tru_mt(A,B,m,n);
	cout<<"\n Tich hai ma tran !"<<endl;
	nhan_mt(A,B,m,n);
	delete []A;
	delete []B;
	getch();
	return 0;
}
float nhap_mt(float *A,int m,int n,char c){
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			cout<<c<<"["<<i<<"]["<<j<<"]\t";
			cin>>A[i*n+j];
		}
}
float cong_mt(float *A,float *B,int m,int n){
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			cout<<A[i*n+j]+B[i*n*j]<<endl;
		}
}
float tru_mt(float *A,float *B,int m,int n){
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			cout<<A[i*n+j]-B[i*n+j]<<endl;
		}
}
float nhan_mt(float *A,float *B,int m,int n){
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			cout<<A[i]*B[j]<<endl;
		}
}
