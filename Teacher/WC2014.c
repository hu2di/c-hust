#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct{
	char hoTen[26];
	char doiTuyen[21];
	int soAo;
}CauThu;
int main(){
	CauThu dsCauThu[100];
	char tmpHoTen[26];
	int i = 0, soCauThu = 0;
	while (i < 100){
		printf("Ho ten cau thu: ");
		fflush(stdin);
		gets(tmpHoTen);
		if (strcmp(tmpHoTen,"*") == 0) break;
		strcpy(dsCauThu[i].hoTen, tmpHoTen);
		printf("Doi tuyen: ");
		fflush(stdin);
		gets(dsCauThu[i].doiTuyen);
		printf("So ao: ");
		scanf("%d",&dsTau[i].soAo);
		i++;
		printf("Nhap thong tin tau tiep theo\n");
	}
	soCauThu = i;
	
	int slTim = 0;
	char tenDoi[21];
	printf("Nhap ten doi tuyen: ");
	fflush(stdin);
	gets(tenDoi);
	printf("Danh sach cau thu thuoc doi tuyen %s\n",tenDoi");
	for(i = 0; i < soTau; i++)
		if (strcmp(dsCauThu[i].doiTuyen,tenDoi){
			printf("%s %d\n",dsCauThu[i].hoTen,dsCauThu[i].soAo);
			slTim++;
		}
	
	if(slTim == 0)
		printf("Khong co cau thu nao");
	
	getch();
	return 0;
	
}