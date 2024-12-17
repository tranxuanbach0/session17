#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void nhapChuoi(char *str) {
    fflush(stdin);
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void inChuoi(char *str) {
    printf("%s\n", str);
}

int demChuCai(char *str) {
    int count = 0;
    while (*str != '\0') {
        if (isalpha(*str)) count++;
        str++;
    }
    return count;
}

int demChuSo(char *str) {
    int count = 0;
    while (*str != '\0') {
        if (isdigit(*str)) count++;
        str++;
    }
    return count;
}

int demKyTuDacBiet(char *str) {
    int count = 0;
    while (*str != '\0') {
        if (!isalpha(*str) && !isdigit(*str) && !isspace(*str)) count++;
        str++;
    }
    return count;
}

int main() {
    char str[100];
    int luaChon;
    int daNhap = 0;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar();

        switch (luaChon) {
            case 1:
                nhapChuoi(str);
                daNhap = 1;
                break;

            case 2:
                if (daNhap) inChuoi(str);
                else printf("Vui long nhap chuoi truoc!\n");
                break;

            case 3:
                if (daNhap) printf("%d\n", demChuCai(str));
                else printf("Vui long nhap chuoi truoc!\n");
                break;

            case 4:
                if (daNhap) printf("%d\n", demChuSo(str));
                else printf("Vui long nhap chuoi truoc!\n");
                break;

            case 5:
                if (daNhap) printf("%d\n", demKyTuDacBiet(str));
                else printf("Vui long nhap chuoi truoc!\n");
                break;

            case 6:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (luaChon != 6);

    return 0;
}

