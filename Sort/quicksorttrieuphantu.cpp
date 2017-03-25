#include <stdio.h>
#include <stdlib.h>
void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}
int choose_pivot(int i,int j )
{
   return((i+j) /2);
}
void quicksort(int list[],int m,int n)
{
   int key,i,j,k;
   if( m < n)
   {
      k = choose_pivot(m,n);
      swap(&list[m],&list[k]);
      key = list[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i] <= key))
                i++;
         while((j >= m) && (list[j] > key))
                j--;
         if( i < j)
                swap(&list[i],&list[j]);
      }
      // hoán 2 phần tử
      swap(&list[m],&list[j]);
      // sắp xếp đệ quy trên danh sách con
      quicksort(list,m,j-1);
      quicksort(list,j+1,n);
   }
}
void printlist(int list[],int n)
{
   int i;
   for(i=0;i<n;i++)
      printf("%d\t",list[i]);
}
void main()
{
   const int MAX_ELEMENTS = 10;
   int list[MAX_ELEMENTS];
   int i = 0;

   // phát sinh ngẫu nhiên và điền vào danh sách
   for(i = 0; i < MAX_ELEMENTS; i++ ){
       list[i] = rand();
   }
   printf("Danh sách trước khi sắp xếp là:\n");
   printlist(list,MAX_ELEMENTS);

   // sắp xếp danh sách dùng quicksort
   quicksort(list,0,MAX_ELEMENTS-1);
   // In kết quả
   printf("Danh sách sau khi sắp xếp dùng thuật toán quicksort:\n");
   printlist(list,MAX_ELEMENTS);
}
