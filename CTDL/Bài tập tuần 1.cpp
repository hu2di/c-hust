#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
#include<fstream>

int sx_ten(char *ptr1[],char *ptr2[],int n,float *ptr3);
int sx_diem(char *ptr1[],char *ptr2[],int n,float *ptr3);
int tim_kiem(char *ptr[50],int n,char ten[50]);

int main(){
	fstream tep1;
		tep1.open("BTLT.txt",ios::out);
	int n;
		cout<<" _____________ \n | Bai tap 1 | \n _____________ \n \n Hay nhap so sinh vien: "; cin>>n;

	char mssv[n][8],*pms[n];
		char sv[n][50],*psv[n],name[50];
			float dtb[n],*p3;
				int i,j;
	for(i=0;i<n;i++){
		pms[i]=mssv[i];
		  p3=dtb;
			fflush(stdin);
			  psv[i]=sv[i];
				cout<<"MSSV"<<i+1<<": "; cin.getline(pms[i],8);
				  cout<<"ten"<<i+1<<":  "; cin.getline(psv[i],50);
					cout<<"DTB"<<i+1<<":  "; cin>>dtb[i];
	}

	/**************Sap xep theo ten*******************/
	cout<<"\n Danh sach SV duoc sap xep theo ten \n ____________________________________________"<<endl;
	  tep1<<"\n Danh sach SV duoc sap xep theo ten"<<endl;
		sx_ten(pms,psv,n,p3);
		  for(i=0;i<n;i++){
			cout<<"\n\t"<<pms[i]<<"\t"<<psv[i]<<"\t"<<p3[i]<<endl;
			  tep1<<"\n\t"<<pms[i]<<"\t"<<psv[i]<<"\t"<<p3[i]<<endl;
	}

	/*************Sap xep theo diem******************/
	cout<<"\n Danh sach sinh vien duoc sap xep theo diem \n ____________________________________________"<<endl;
	tep1<<"\n Danh sach sinh vien duoc sap xep theo diem"<<endl;
	sx_diem(pms,psv,n,p3);
	  for(i=0;i<n;i++){
		cout<<"\n\t"<<pms[i]<<"\t"<<psv[i]<<"\t"<<p3[i]<<endl;
		  tep1<<"\n\t"<<pms[i]<<"\t"<<psv[i]<<"\t"<<p3[i]<<endl;
	}

	/*************Tim kiem sinh vien****************/
	cout<<"\nNhap ten sv can tim: "<<endl;
	  tep1<<"\nNhap ten sv can tim: "<<endl;
		fflush(stdin);
		  cin.getline(name,50);
			tep1<<name<<endl;
				tim_kiem(psv,n,name);
	getch();
	return 0;
}

int sx_ten(char *ptr1[],char *ptr2[],int n,float *ptr3){
	char *p;
	int i,j;
	float tg;
	for(i=0;i<n;i++)
	  for(j=i+1;j<n;j++){
		if(stricmp(ptr2[i],ptr2[j])>0){
		  p=ptr1[i]; ptr1[i]=ptr1[j]; ptr1[j]=p;
			p=ptr2[i]; ptr2[i]=ptr2[j]; ptr2[j]=p;
			  tg=ptr3[i]; ptr3[i]=ptr3[j]; ptr3[j]=tg;
		}
		else if(stricmp(ptr2[i],ptr2[j])==0){
		  if(ptr3[i]<ptr3[j]){
			p=ptr1[i]; ptr1[i]=ptr1[j]; ptr1[j]=p;
			  p=ptr2[i]; ptr2[i]=ptr2[j]; ptr2[j]=p;
				tg=ptr3[i]; ptr3[i]=ptr3[j]; ptr3[j]=tg;
		  }
		}
	  }
		return 1;
}
int sx_diem(char *ptr1[],char *ptr2[],int n,float *ptr3){
	char *p;
	int i,j;
	float tg;
	for(i=0;i<n;i++)
	  for(j=i+1;j<n;j++){
		if(ptr3[i]<ptr3[j]){
		  p=ptr1[i]; ptr1[i]=ptr1[j]; ptr1[j]=p;
			p=ptr2[i]; ptr2[i]=ptr2[j]; ptr2[j]=p;
			  tg=ptr3[i]; ptr3[i]=ptr3[j]; ptr3[j]=tg;
		}
	  }
		return 1;
}
int tim_kiem(char *ptr[50],int n,char ten[50]){
	int dau=0,cuoi=n-1,vtri;
	while(dau<=cuoi){
	  vtri=(dau+cuoi)/2;
		if(stricmp(ptr[vtri],ten)>0) cuoi=vtri-1;
		  else if(stricmp(ptr[vtri],ten)<0) dau=vtri+1;
			else if(stricmp(ptr[vtri],ten)==0){
			  cout<<"Vtri co ten "<<vtri+1;
				break;
			}
	}
	return 1;
}
