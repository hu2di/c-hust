#include<iostream>
#include<math.h>
using namespace std;
int main()
{
float a=1.,b=1.,c=sqrt(2);
cout<<(a+b-pow(c,2))<<endl;
if (a+b-pow(c,2)==0)
cout<<"TRUE"<<endl;
else
cout<<"FALSE"<<endl;
cout<<c<<endl;
cout<<pow(c,2)<<endl;
cout<<c<<endl;
cout<<a+b-pow(c,2)<<endl;
return 0;
}
