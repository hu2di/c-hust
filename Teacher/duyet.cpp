#include<iostream>
#include<list>
#include<queue>
#include<conio.h>
#include<stack>
#include<stdio.h>
using namespace std;
class DoThi
{
private:
int v;
list<int> *dscacdinh;
public:
DoThi(int sodinh);
void themCanh(int u, int v);//Them canh u - >v
void BFS(int d_batdau);
void DFS(int _start);
~DoThi();
private:
};
DoThi::DoThi(int sodinh)
{
this->v = sodinh;
this->dscacdinh = new list<int>[v];
}
void DoThi::themCanh(int u, int v)
{
dscacdinh[u].push_back(v);
}
void DoThi::BFS(int d_start)
{
queue<int> myqueue;
bool datham[100] = { false };
datham[d_start] = true;
myqueue.push(d_start);
list<int>::iterator ptr;
while (!myqueue.empty())
{
d_start = myqueue.front();
cout << d_start << " ";
myqueue.pop();
for (ptr = dscacdinh[d_start].begin(); ptr != dscacdinh[d_start].end(); ptr++)
{
if (!datham[*ptr])
{
datham[*ptr] = true;
myqueue.push(*ptr);
}
}
}
}
void DoThi::DFS(int _start)
{
stack<int> mystack;
bool datham[50] = {false};
datham[_start] = true;
mystack.push(_start);
list<int>::iterator ptr;
while (!mystack.empty())
{
_start = mystack.top();
cout << _start << " ";
mystack.pop();
for ( ptr=dscacdinh[_start].begin(); ptr!=dscacdinh[_start].end(); ptr++)
{
if (!datham[*ptr])
{
mystack.push(*ptr);
datham[*ptr] = true;
}
}
}
}
DoThi::~DoThi()
{
}
int main()
{
freopen("data.txt","r",stdin);
int k=0;
DoThi test(9);
int u,v;
cin>>k;
int flag=0,checkbegin=0;
int i=0;
while(k--)
{
cin>>u>>v;
test.themCanh(u,v);
}
cout<<" Bai tap duyet do thi theo DFS va BFS \n";
cout << "Duyet do thi theo chieu rong BFS : ";
test.BFS(1);
cout<<endl;
cout<<"Duyet do thi theo chieu sau DFS : ";
test.DFS(1);
_getch();
}
