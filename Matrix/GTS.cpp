#include<stdio.h>
#include<math.h>
#include<conio.h> //Neu bien dich tren Linux thi khong can thu vien nay

int n;// So luong hang cot ma tran A
long double *p,*q;// Mang luu tru ma tran
int *h,*c;//Mang luu cac hang cot da tinh

int confg[7]={10,7,10,7,10,7,1};//Mang luu du lieu cai dat

int config();// load file config
int input();// load file du lieu
long double max(); // Tim phan tu giai
void tinhh(long double ptg);// Tinh toan hang cot cua ma tran

int main(){
  long double k,nghiem=0;
  if(config())
    printf("\nLoi load file config cac gia tri  cai dat se de mac dinh \n");
    
  if(input()){
    printf("Loi doc file \n");
    return 0;
  }
  printf("Matran mo rong \n");
  for(int j=0;j<n;j++){
    for(int i=0;i<=n;i++){
      if(i==n) printf("|");
      printf("%*.*Lf ",confg[0],confg[1],*(p+j*(n+1)+i));
    }
      printf("\n");
  }
  
  for(int i=0;i<n;i++){
    k=max();
    if(k==0){
      printf("Vo so nghiem \n");
      return 0;
    }
    tinhh(k);
  }
  
  printf("\nNghiem cua he la :\n");
  for(int j=0;j<n;j++){
    printf("Nghiem X%d = %*.*Lf\n",j+1,confg[2],confg[3],(*(p+*(h+j)*(n+1)+n))/(*(p+*(h+j)*(n+1)+*(c+j))));
  }
  
 getch(); // Neu bien dich tren linux thi khong can lenh nay
return 0;
}

int config(){
    FILE *file=NULL;
    if((file=fopen("config.txt","r"))==NULL) return 1;
    for(int i=0;i<7;i++)
      if(fscanf(file,"%d",&confg[i])==EOF) return 1;
return 0;
}

int input(){
  FILE *file=NULL;
  if((file=fopen("input.txt","r"))==NULL) return 1;
  fscanf(file,"%d",&n);
  p=new long double[n*(n+1)];
  q=new long double[n*(n+1)];
  h=new int[n];
  c=new int[n];
  for(int j=0;j<n;j++){
    for(int i=0;i<=n;i++)
      if(fscanf(file,"%Lf",(p+j*(n+1)+i))==EOF) return 1;
    *(h+j)=*(c+j)=-1;
    }
    
    for(int j=0;j<n;j++)
      for(int i=0;i<=n;i++)
        *(q+j*(n+1)+i)=*(p+j*(n+1)+i);
  return 0;
}

void them(int *mang,int gt){
  for(int i=0;i<n;i++){
    int k=*(mang+i);
    *(mang+i)=gt;
    gt=k;
  }
}

long double max(){
  long double ptg;
  int kt=1,vtj,vti;
  for(int j=0;j<n;j++)
    for(int i=0;i<n;i++){
      int dk=1;
      for(int lb=0;lb<n;lb++) if((i==*(c+lb))||(j==*(h+lb))){
        dk=0;break;
      }
      if(dk){
        if(kt){
          kt=0;ptg=*(p+j*(n+1)+i);
          vtj=j;vti=i;
        }
        if(fabs(*(p+j*(n+1)+i))>fabs(ptg)){
          ptg=*(p+j*(n+1)+i);
          vtj=j;vti=i;
        }
      }
    }
    them(h,vtj);
    them(c,vti);
    return ptg;
}

void tinhh(long double ptg){
  for(int j=0;j<n;j++){
    if(j==*h) continue;
    long double mj=*(p+j*(n+1)+*c)/ptg;
    for(int i=0;i<=n;i++)
      *(q+j*(n+1)+i)=*(p+j*(n+1)+i)-*(p+*h*(n+1)+i)*mj;
  }
   for(int j=0;j<n;j++)
    for(int i=0;i<=n;i++)
      *(p+j*(n+1)+i)=*(q+j*(n+1)+i);
    
    if(confg[6]) return ;
      printf("\n");
  for(int j=0;j<n;j++){
    for(int i=0;i<=n;i++){
      if(i==n) printf("|");
      printf("%*.*Lf ",confg[4],confg[5],*(p+j*(n+1)+i));
    }
      printf("\n");
  }

}
