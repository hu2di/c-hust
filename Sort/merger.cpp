void merge(int a[], int a1, int a2, int a3){
int i, j, k, t;
int temp[10];
i = a1;
j = a2;
k = a1;
while (i < a2 && j <= a3){
if (a[i] < a[j]){
temp[k] = a[i];
i++;
}
else{
temp[k] = a[j];
j++;
}
k++;
}
if (i >= a2)
for (t = j; t <= a3; t++){
temp[k] = a[t];
k++;
}
else
for (t = i; t <= a2; t++){
temp[k] = a[t];
k++;
}
for (k = a1; k <= a3; k++)
a[k] = temp[k];
}
void merge_sort(int a[], int k1, int k3){
int k2;
if (k1 < k3){
k2 = int((k1 + k3)/2);
merge_sort(a, k1, k2);
merge_sort(a, k2 + 1, k3);
merge(a, k1, k2, k3);
}
}
