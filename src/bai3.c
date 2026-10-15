#include <stdio.h>

#define MAX_COLS 100

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
void maTranBinhPhuong(int src[][MAX_COLS], int dest[][MAX_COLS], int row, int col);

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

    printf("Nhap cac phan tu cua ma tran (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("  src[%d][%d] = ", i, j);
            scanf("%d", &src[i][j]);
        }
    }

    maTranBinhPhuong(src, dest, row, col);

    printf("\nMa tran binh phuong:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", dest[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
void maTranBinhPhuong(int src[][MAX_COLS], int dest[][MAX_COLS], int row, int col) {
    // TODO: Tính bình phương từng phần tử của ma trận src và lưu sang ma trận dest
    // dest[i][j] = src[i][j] * src[i][j]
    // Giữ nguyên dữ liệu trong ma trận gốc src
    // LƯU Ý: Tuyệt đối không dùng lệnh in (printf) bên trong hàm này
    
}
