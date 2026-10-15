#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
void sapXepGiamDan(float a[], int n);

#ifndef UNIT_TEST
int main() {
    int n;
    float a[100];

    printf("Nhap so luong chi so hieu suat (n > 0): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong khong hop le!\n");
        return 0;
    }

    printf("Nhap %d chi so hieu suat:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  Diem a[%d]: ", i);
        scanf("%f", &a[i]);
    }

    printf("\nMang truoc khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");

    sapXepGiamDan(a, n);

    printf("\n--- BANG XEP HANG HIEN THI (GIAM DAN) ---\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %.2f%s", i, a[i], (i < n - 1) ? ", " : "\n");
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
void sapXepGiamDan(float a[], int n) {
    // TODO: Sắp xếp các phần tử trong mảng a theo thứ tự GIẢM DẦN (a[0] >= a[1] >= ... >= a[n-1])
    // Thao tác sắp xếp trực tiếp trên mảng truyền vào (in-place)
    // LƯU Ý: Tuyệt đối không dùng lệnh in (printf) bên trong hàm này
    
}
