#include <stdio.h>

#define MAX_COLS 100

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
int locSoLeMaTran(int a[][MAX_COLS], int row, int col, int hangLe[], int cotLe[], int giaTriLe[]);

#ifndef UNIT_TEST
int main() {
    int row, col;
    int a[100][MAX_COLS];
    int hangLe[10000], cotLe[10000], giaTriLe[10000];

    printf("Nhap so hang (row > 0): ");
    scanf("%d", &row);
    printf("Nhap so cot  (col > 0): ");
    scanf("%d", &col);

    if (row <= 0 || col <= 0 || row > 100 || col > 100) {
        printf("Kich thuoc ma tran khong hop le!\n");
        return 0;
    }

    printf("Nhap cac phan tu cua ma tran (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("  a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    int soLuongLe = locSoLeMaTran(a, row, col, hangLe, cotLe, giaTriLe);

    printf("\n--- DANH SACH PHAN TU LE TRONG MA TRAN ---\n");
    if (soLuongLe == 0) {
        printf("Khong co phan tu le trong ma tran.\n");
    } else {
        for (int k = 0; k < soLuongLe; k++) {
            printf("Phan tu le tai a[%d][%d] = %d\n", hangLe[k], cotLe[k], giaTriLe[k]);
        }
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
int locSoLeMaTran(int a[][MAX_COLS], int row, int col, int hangLe[], int cotLe[], int giaTriLe[]) {
    // TODO: Duyệt ma trận a[][], tìm tất cả các phần tử là số lẻ (kể cả số lẻ âm)
    // Lưu tọa độ hàng vào hangLe[], cột vào cotLe[], giá trị vào giaTriLe[]
    // Trả về tổng số lượng phần tử lẻ tìm thấy
    // LƯU Ý KỸ THUẬT: Điều kiện kiểm tra số lẻ trong C là: a[i][j] % 2 != 0
    // Tuyệt đối không dùng lệnh in (printf) bên trong hàm này
    
    return 0;
}
