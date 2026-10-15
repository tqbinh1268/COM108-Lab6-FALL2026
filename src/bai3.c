#include <stdio.h>

#define MAX_COLS 100

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
void lamMoMaTran(int src[][MAX_COLS], int dest[][MAX_COLS], int row, int col);

#ifndef UNIT_TEST
int main() {
    int row, col;
    int src[100][MAX_COLS];
    int dest[100][MAX_COLS];

    printf("Nhap so hang (row > 0): ");
    scanf("%d", &row);
    printf("Nhap so cot  (col > 0): ");
    scanf("%d", &col);

    if (row <= 0 || col <= 0 || row > 100 || col > 100) {
        printf("Kich thuoc ma tran khong hop le!\n");
        return 0;
    }

    printf("Nhap cac diem anh cua ma tran (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("  src[%d][%d] = ", i, j);
            scanf("%d", &src[i][j]);
        }
    }

    lamMoMaTran(src, dest, row, col);

    printf("\n--- MA TRAN ANH DA LAM MO (BOX BLUR 3x3) ---\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d ", dest[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
void lamMoMaTran(int src[][MAX_COLS], int dest[][MAX_COLS], int row, int col) {
    // TODO: Áp dụng bộ lọc làm mờ Box Blur 3x3 cho ma trận ảnh src lưu sang dest
    // Với mỗi ô (i, j):
    //   - Xét các ô lân cận (r, c) trong phạm vi [i-1 .. i+1] và [j-1 .. j+1]
    //   - CHỈ lấy các ô hợp lệ: 0 <= r < row và 0 <= c < col
    //   - Tính: dest[i][j] = tong_cac_o_hop_le / so_luong_o_hop_le (phép chia nguyên)
    // Giữ nguyên ma trận gốc src.
    // LƯU Ý: Cực kỳ cẩn thận xử lý biên (ô góc có 4 lân cận, ô cạnh có 6 lân cận, ô tâm có 9 lân cận)
    // Tuyệt đối không dùng lệnh in ra màn hình bên trong hàm này!
    
}
