#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct LienLac {
    char ten[51];
    char sdt[21];
};

typedef struct LienLac LL;

int LinearSearch(LL danhsach[], int n, char k[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(danhsach[i].ten, k) == 0) {//strcmp so sánh 2 xâu kí tự
            return i;
        }
    }
    return -1;
}


int main() {
    FILE* file;
    LL Ds[51];
    int solienlac = 0;

    file = fopen("DanhBa.txt", "r");
    if (file == NULL) {
        printf("Khong the mo tep DanhBa.txt\n");
        return 1;
    }

    while (fscanf(file, "%50s %20s", Ds[solienlac].ten, Ds[solienlac].sdt) == 2) {
        solienlac++;
        if (solienlac >= 100) {
            printf("Danh ba khong the doc them.\n");
            break;
        }
    }
    fclose(file);

    char k[51];
    printf("Nhap ten lien lac can tim: ");
    fgets(k, sizeof(k), stdin);
    k[strcspn(k, "\n")] = '\0';

    int kp = LinearSearch(Ds, solienlac, k);
    if (kp != -1) {
        printf("Lien lac '%s' co so dien thoai: %s\n", Ds[kp].ten, Ds[kp].sdt);
    }
    else {
        printf("Khong tim thay lien lac '%s' trong danh ba.\n", k);
    }
    
    return 0;
}
