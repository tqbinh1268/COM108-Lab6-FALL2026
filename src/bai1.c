#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
int timMaxMin(float a[], int n, float *maxVal, float *minVal);

#ifndef UNIT_TEST
int main() {
    int n;
    float a[100];
    float maxVal, minVal;

    printf("Nhap so luong cam bien nhiet do (n > 0): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong cam bien khong hop le!\n");
        return 0;
    }

    printf("Nhap gia tri nhiet do cua %d cam bien:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  Cam bien a[%d]: ", i);
        scanf("%f", &a[i]);
    }

    int kq = timMaxMin(a, n, &maxVal, &minVal);

    if (kq == 1) {
        printf("\n--- KET QUA GIAM SAT NHIET DO ---");
        printf("\nNhiet do cao nhat: %.2f do C", maxVal);
        printf("\nNhiet do thap nhat: %.2f do C\n", minVal);
    } else {
        printf("\nLoi: Du lieu khong hop le de xu ly!\n");
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
int timMaxMin(float a[], int n, float *maxVal, float *minVal) {
    // TODO: Tìm giá trị lớn nhất và nhỏ nhất trong mảng a gồm n phần tử
    // Gán kết quả vào *maxVal và *minVal
    // Trả về 1 nếu thành công (n > 0), trả về 0 nếu n <= 0
    // LƯU Ý: Tuyệt đối không dùng printf/scanf bên trong hàm này
    
    return 0;
}
