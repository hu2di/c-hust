#include <stdio.h>
#include <conio.h>

int main()
{
    printf("\nChuong trinh minh hoa KIEU KY TU \n\n");
    char ch;              //khai báo biến ch kiểu char
    ch = 'a';             //gán giá trị 'a' cho biết ch
    printf("%c ", ch);    //hiển thị giá trị của ch dưới dạng ký tự
    printf("%d ", ch);    //hiển thị giá trị của ch dưới dạng số nguyên
    ch = ch + 1;          //tăng ch lên 1 đơn vị
    printf("%c\n\n", ch); //hiển thị giá trị của ch dưới dạng ký tự
}
