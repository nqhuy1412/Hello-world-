#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>

struct HangHoa {
    char ten[21];
    int soluong;
};

typedef struct HangHoa HH;

int LinearSearch(HH Ds[], int n, char k[]) {    // k là hàng hóa cần tìm
    for (int i = 0; i < n; i++) {
        if (strcmp(Ds[i].ten, k) == 0) {  
            return i;
        }
    }
    return -1;
}

int main() {
    FILE* file;
    HH Ds[51];
    int soluonghanghoa = 0;
    file = fopen("KhoHang.txt", "r");
    if (file == NULL) {
        printf("Khong the mo tep KhoHang.txt\n");
        return 1;
    }

    while (fscanf(file, "%s %d", Ds[soluonghanghoa].ten, &Ds[soluonghanghoa].soluong) == 2) {
        soluonghanghoa++;
        if (soluonghanghoa >= 50) {
            printf("Kho hang qua lon, khong the doc them.\n");
            break;
        }
    }
    fclose(file);

    char k[51];
    printf("Nhap ten hang hoa can tim: ");
    fgets(k, sizeof(k), stdin);   //sizeof(hangcantim) có thể thay = 99
    k[strcspn(k, "\n")] = '\0';//gets

    int kp = LinearSearch(Ds, soluonghanghoa,k);
    if (kp != -1) {
        printf("Hang hoa '%s' co ton tai trong kho voi so luong: %d\n", Ds[kp].ten, Ds[kp].soluong);
    }
    else {
        printf("Hang hoa '%s' khong ton tai trong kho.\n", k);
    }

    return 0;
}
