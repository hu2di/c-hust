#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct Do_dai
{
	int L;
	struct Do_dai *next;
} Dd;
int Capphat(int** &A,int M,int N);
void NhapMT(int** &A,int M,int N,char Sbol);
void Giaiphong(int** &Mt);

int main()
{
	int m,n,i,j,k,c1,max;
	Dd *ptr,*ptr1,*head=NULL;
	int **A=NULL;
	cout<<"Chuong trinh tim day so 1 dai nhat trong ma tran nhi phan\n";
	cout<<"Nhap kich thuoc ma tran:\n";
	cout<<"Nhap so hang:\n";
	cin>>m;
	cout<<"Nhap so cot:\n";
	cin>>n;
	m++;
	n++;
	head=NULL;
	if(Capphat(A,m,n))
	{
		cout<<"Khong du bo nho"<<endl;
		return 0;
		
	}
	cout<<"Nhap ma tran:"<<endl;
	NhapMT(A,m,n,'A');
	for(i=0;i<m;i++)
	{
		c1=-1;
		j=-1;
    
	    for(k=j+1;k<=n;k++)
	    {
	    	
	    	if(A[i][k]==0)
	    	{
	    	ptr=(struct Do_dai*) calloc(1,sizeof(struct Do_dai));
	    	ptr->L= k-c1-1;
	    	c1=k;
	    	ptr->next= head;
	    	head=ptr;
	    	j=k;
	        }
	    }
	}
	
	for(j-0;j<n;j++)
	{
		c1=-1;
		i=-1;
		for(k=i+1;k<m;k++)
		{
			if(A[k][j]==0)
			{
			ptr= (struct Do_dai*) calloc(1,sizeof(struct Do_dai));
			ptr->L= k-c1-1;
			c1=k;
			ptr->next= head;
			head=ptr;
			i=k;
		    }
			
		}
	}
	ptr=head;
	max=ptr->L;
	while(ptr!=NULL)
	{
	
		if(max<ptr->L)
		max=ptr->L;
		ptr=ptr->next;
		
	}
	cout<<"\n\n Day so 1 co do dai lon nhat la: "<<max;
	Giaiphong(A);
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr1=ptr;
		ptr=ptr->next;
		delete(ptr1);
	}
	delete(head);
	delete(ptr);
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
		if((i<M-1)&&(j<N-1))
		{
			cout<<Sbol<<"["<<i<<"]["<<j<<"]= ";cin>> A[i][j];
		}
		if(((i==M-1)&&(j!=N-1))||((j==N-1)&&(i!=M-1))) A[i][j]=0;
		
	}
}
