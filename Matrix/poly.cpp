#include<iostream>

using namespace std;
int n;
void _nhap(float* a,int* n);
void _in(float* a,int n);
float _polyvalue(float* a,int n);
int main(){
    cout<<" \nChuong trinh tinh da thuc mu n \n_______________________________";
    float a[100];
    _nhap(a,&n);
    _in(a,n);
    cout<<"\n gia tri da thuc: "<<_polyvalue(a,n);
}

void _nhap(float* a,int* n){
    int i;
        do{
    cout<<"\n\nNhap bac cua da thuc: ";
    cin>>*n;
    }while(*n>100);
    for(i=*n;i>=0;i--){
        cout<<"\nNhap  a"<<i<<"  :   ";
        cin>>a[i];
    }
    while(a[*n]==0)
        *n=*n-1;

}

void _in(float* a,int n){
    int i;
    cout<<"\n";
    for(i=n;i>0;i--){
        if(a[i-1]!=0)
            cout<<a[i]<<"*x^"<<i<<"  +  ";
        else
            cout<<a[i]<<"*x^"<<i;
    }
    if(a[0]!=0) cout<<a[0]<<"\n\n";
}

float _polyvalue(float* a,int n){
    float s,x;
    int i=0;
    cout<<"\nTinh gia tri da thuc tai x=  ";
    cin>>x;
    s=a[n]*x+a[n-1];
    for(i=2;i<=n;i++){
        s=s*x+a[n-i];
    }
    return s;

}
