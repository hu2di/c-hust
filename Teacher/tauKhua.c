#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct{
	char soHieu[11];
	char chungLoai[26];
	int viTri;
}tauKhua;
int main(){
	tauKhua dsTau[80];
	char tmpSoHieu[11];
	int i = 0, soTau = 0;
	while (i < 80){
		printf("So hieu tau: ");
		fflush(stdin);
		gets(tmpSoHieu);
		if (strcmp(tmpSoHieu,"#") == 0) break;
		strcpy(dsTau[i].soHieu, tmpSoHieu);
		printf("Chung loai: ");
		fflush(stdin);
		gets(dsTau[i].chungLoai);
		printf("Vi tri: ");
		scanf("%d",&dsTau[i].viTri);
		i++;
		printf("Nhap thong tin tau tiep theo\n");
	}
	soTau = i;
	
	int tauTrongTamBan = 0;
	printf("Cac tau trong tam ban la:\n");
	for(i = 0; i < soTau; i++)
		if (dsTau[i].viTri<=180){
			printf("%s",dsTau[i].soHieu);
			tauTrongTamBan++;
		}
	
	if(tauTrongTamBan > 0)
		printf("So tau trong tam ban la: %d",tauTrongTamBan);
	else printf("Khong co tau nam trong tam ban");
	
	getch();
	return 0;
	
}