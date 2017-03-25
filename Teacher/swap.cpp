#include<iostream>
using namespace std;
void swap1(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void swap2(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;

}
void swap3(int *a,int *b)
{

    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

}
int main()
{
    cout<<"\nTHU NGHIEM CAC LOAI SWAP.HAIZZ.\n";
    int a,b;
    cout<<"\nTham tri:\n";
    cout<<"a=";
    cin>>a;
    cout<<"\nb=";
    cin>>b;
    swap1(a,b);
    cout<<"\na= "<<a<<"   b= "<<b;
    cout<<"\nTham chieu:\n";
    cout<<"a=";
    cin>>a;
    cout<<"\nb=";
    cin>>b;
    swap2(a,b);
    cout<<"\na= "<<a<<"   b= "<<b;
    cout<<"\nTham tro:\n";
    cout<<"a=";
    cin>>a;
    cout<<"\nb=";
    cin>>b;
    swap3(&a,&b);
    cout<<"\na= "<<a<<"   b= "<<b;
}
