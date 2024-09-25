#include<stdio.h>

void NhapValue(int* n) {
	printf("Nhap gia tri o nho: ");
	scanf_s("%d", n);
}

void NhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap gia tri cua a[%d]: ", i);
		scanf_s("%d", &a[i]);
	}
}

void XuatMang(int a[], int n) {
	printf("\nMang cua ban la: ");
	for (int i = 0; i < n; i++) {
		printf("%4d", a[i]);
	}
}

//Sorting algorithm( Thuật toán sắp xếp )
void Swap(int& x, int& y) {	// Truyền tham chiếu vào hàm 
	int temp = x;
	x = y;
	y = temp;
}

//1 Selection sort (Sắp xếp lựa chọn)  



void SelefctionS(int a[], int n) {
	int min;
	for (int i = 0; i < n; i++) {
		min = i;		// Min sẽ được cập nhật liên tục
		for (int j = i + 1; j < n; j++) {
			if (a[min] > a[j])
				min = j;
		}
		Swap(a[i], a[min]);		//Thay đổi giá trị phần tử
	}
}

int main() {
	int n;
	NhapValue(&n);
	int a[100];
	NhapMang(a, n);
	SelefctionS(a, n);
	XuatMang(a, n);
	return 0;
}