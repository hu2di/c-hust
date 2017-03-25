#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAX 100
typedef struct Tong
{
	int S;
	int a;
	int b;
	struct Tong *next;
} Sum;
int main()
{
	int day[MAX];
	Sum *sum,*last,*max,*p;
	int i=0,j,k,n,dau,cuoi;
	// Nhap du lieu
	cout<<"Nhap so phan tu cua day:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Nhap phan tu thu "<<i+1<<": ";
		cin>>day[i];
	}
	//Tim day tang va tinh tong cho vao mang cap phat dong da khai bao
	last=NULL;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;)
		{
			if(day[j]<=day[j+1]&&j!=(n-1))
			{
			    j++;
			    continue;
			}
			    
			     
			else
			{
				sum= (struct Tong*) calloc(1,sizeof(struct Tong));
				sum->S=0;
				for(k=i;k<=j;k++)
				sum->S= sum->S + day[k];
				sum->a =i;
				sum->b=j;
				i=j;
				sum->next=last;
				last= sum;
			} break;
			
			
		} 
	}
	//in ra ket qua
	sum=last;
	max=sum;
	while(sum!= NULL)
	{
		
		if(max->S <sum->S) max= sum;
		sum= sum->next;
	}
	
	cout<<"Day con tang co tong lon nhat la:"<<endl;
	dau=max->a;
	cuoi= max->b;
	for(i= dau;i<= cuoi;i++)
	cout<<day[i]<<" ;";
	cout<<endl;
	cout<<"Tong = "<<max->S;
	sum=last;
	while(sum!= NULL)
	{
		p = sum;
		sum=sum->next;
		delete(p);
		;
	}
	delete(max);
	delete(sum);
	delete(last);
	getch();
	return 0;
	
	
	
}
