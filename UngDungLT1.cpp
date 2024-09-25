#include<stdio.h>

int TimSoChan(int x) {
	if (x % 2 == 0) return x;
	return 0;
}

int main() {
	int n;
	printf("Nhap n: ");
	scanf_s("%d", &n);
	int a[100];
	for (int i = 0; i < n; i++) {
		printf("Nhap a[%d]", i);
		scanf_s("%d", &a[i]);
	}
	printf("So luong phan tu chan trong mang la: ");
	for (int i = 0; i < n; i++) {
		if(TimSoChan(a[i]) != 0)
			printf("%4d", TimSoChan(a[i]));
	}
	return 0;
}