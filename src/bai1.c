#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
void lamMinTinHieu(float raw[], float smooth[], int n);

#ifndef UNIT_TEST
int main() {
    int n;
    float raw[100];
    float smooth[100];

    printf("Nhap so luong mau tin hieu cam bien (n > 0): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong mau khong hop le!\n");
        return 0;
    }

    printf("Nhap %d gia tri tin hieu tho:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  raw[%d] = ", i);
        scanf("%f", &raw[i]);
    }

    lamMinTinHieu(raw, smooth, n);

    printf("\n--- KET QUA LAM MIN TIN HIEU (MOVING AVERAGE) ---\n");
    printf("Tin hieu goc: ");
    for (int i = 0; i < n; i++) printf("%.2f ", raw[i]);
    printf("\nTin hieu min: ");
    for (int i = 0; i < n; i++) printf("%.2f ", smooth[i]);
    printf("\n");

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
void lamMinTinHieu(float raw[], float smooth[], int n) {
    // TODO: Tính mảng smooth[] từ mảng raw[] theo thuật toán trung bình trượt cửa sổ k = 3
    // QUY TẮC XỬ LÝ BIÊN:
    // - Nếu n = 1: smooth[0] = raw[0]
    // - Với n >= 2:
    //   + Tại ô đầu (i = 0):     smooth[0] = (raw[0] + raw[1]) / 2.0f
    //   + Tại ô cuối (i = n-1):  smooth[n-1] = (raw[n-2] + raw[n-1]) / 2.0f
    //   + Tại ô giữa (1 <= i <= n-2): smooth[i] = (raw[i-1] + raw[i] + raw[i+1]) / 3.0f
    // LƯU Ý: Tuyệt đối không đọc tràn mảng và không dùng lệnh in ra màn hình trong hàm!
    
}
