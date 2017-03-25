// PhongBM
// UET - VNU
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
using namespace std;
#define MAX 10
int main(){
	int a[MAX], n, left[MAX], right[MAX], max=2, k=0;
	cout << "Enter value of n = "; cin >> n;
	for(int i=0;i<n;i++){
		cout << "a[" << i << "] = "; cin >> a[i];
	}
	for(int i=0;i<n-1;i++){
		int count=1;
		int j=i;
		while(a[j]<=a[j+1]&&j<n-1){
			count++;
			j++;
		}
		if(count>=max){
			if(count>max)
				k=0;
			max=count;
			left[k]=i;
			right[k]=j;
			k++;
		}
	}
	cout << "Array does not reduced which length is largest:\n";
	for(int i=0;i<k;i++){
		for(int j=left[i];j<=right[i];j++){
			cout << a[j] << "\t";
		}
		cout << "\n";
	}
    Sleep(3000);
}
