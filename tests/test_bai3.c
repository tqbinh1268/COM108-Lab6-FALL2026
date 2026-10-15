#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_TEST
#include "../src/bai3.c"

int main() {
    printf("[CHAY TEST BAI 3: MA TRAN BINH PHUONG]\n");

    // 1. Kiểm tra kiến trúc: Cấm dùng printf trong hàm maTranBinhPhuong
    FILE *f = fopen("src/bai3.c", "r");
    if (f) {
        char line[256];
        int inHam = 0;
        while (fgets(line, sizeof(line), f)) {
            if (strstr(line, "SINH VIÊN VIẾT CODE")) inHam = 1;
            if (inHam && strstr(line, "printf")) {
                printf("FAILED Kien truc: Phat hien lenh 'printf' ben trong ham maTranBinhPhuong!\n");
                printf("--> YEU CAU: Ham chi tinh toan luu ket qua vao dest[][]. In an dang bang phai nam o main()!\n");
                fclose(f);
                return 1;
            }
        }
        fclose(f);
    }

    // 2. Test chuẩn: Ma trận 2 hàng x 3 cột
    int src1[100][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int dest1[100][MAX_COLS] = {0};
    int expected1[2][3] = {
        {1, 4, 9},
        {16, 25, 36}
    };

    maTranBinhPhuong(src1, dest1, 2, 3);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (dest1[i][j] != expected1[i][j]) {
                printf("FAILED Test 1: Tai dest[%d][%d] -> Expected: %d, Actual: %d\n",
                       i, j, expected1[i][j], dest1[i][j]);
                return 1;
            }
        }
    }

    // Kiểm tra ma trận nguồn src không bị thay đổi dữ liệu
    if (src1[0][0] != 1 || src1[1][2] != 6) {
        printf("FAILED Test 1: Ma tran goc src bi ghi de du lieu thay vi luu sang dest!\n");
        return 1;
    }

    // 3. Test số âm và số 0: Ma trận 2 x 2
    int src2[100][MAX_COLS] = {
        {-3, 0},
        {5, -7}
    };
    int dest2[100][MAX_COLS] = {0};
    int expected2[2][2] = {
        {9, 0},
        {25, 49}
    };

    maTranBinhPhuong(src2, dest2, 2, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (dest2[i][j] != expected2[i][j]) {
                printf("FAILED Test 2: Binh phuong so am/0 tai dest[%d][%d] -> Expected: %d, Actual: %d\n",
                       i, j, expected2[i][j], dest2[i][j]);
                return 1;
            }
        }
    }

    printf(">>> BAI 3: PASS 100%% TEST CASES!\n");
    return 0;
}
