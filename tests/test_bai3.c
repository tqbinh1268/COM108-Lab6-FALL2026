#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_TEST
#include "../src/bai3.c"

int main() {
    printf("[CHAY TEST BAI 3: BO LOC LAM MO DIEM ANH BOX BLUR 3x3]\n");

    // 1. Kiểm tra kiến trúc: Cấm dùng printf trong hàm lamMoMaTran
    FILE *f = fopen("src/bai3.c", "r");
    if (f) {
        char line[256];
        int inHam = 0;
        while (fgets(line, sizeof(line), f)) {
            if (strstr(line, "SINH VIÊN VIẾT CODE")) inHam = 1;
            if (inHam && strstr(line, "printf(")) {
                printf("FAILED Kien truc: Phat hien lenh 'printf' ben trong than ham lamMoMaTran!\n");
                printf("--> YEU CAU: Ham chi ghi ket qua vao dest[][]. In an phai o main()!\n");
                fclose(f);
                return 1;
            }
        }
        fclose(f);
    }

    // 2. Test chuẩn: Ma trận 3 x 3
    int src1[100][MAX_COLS] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };
    int dest1[100][MAX_COLS] = {0};
    int exp1[3][3] = {
        {30, 35, 40},
        {45, 50, 55},
        {60, 65, 70}
    };

    lamMoMaTran(src1, dest1, 3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (dest1[i][j] != exp1[i][j]) {
                printf("FAILED Test 1 (3x3): Tai dest[%d][%d] -> Expected: %d, Actual: %d\n",
                       i, j, exp1[i][j], dest1[i][j]);
                return 1;
            }
        }
    }

    // Kiểm tra ma trận gốc không bị ghi đè
    if (src1[0][0] != 10 || src1[1][1] != 50 || src1[2][2] != 90) {
        printf("FAILED Test 1: Ma tran goc src bi sua doi du lieu trong qua trinh tinh!\n");
        return 1;
    }

    // 3. Test bẫy AI: Ma trận 2 x 2 (AI hay chia cố định cho 9 thay vì đếm số ô hợp lệ)
    int src2[100][MAX_COLS] = {
        {4, 8},
        {12, 16}
    };
    int dest2[100][MAX_COLS] = {0};
    lamMoMaTran(src2, dest2, 2, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (dest2[i][j] != 10) {
                printf("FAILED Test 2 (Bay AI bien 2x2): Tai dest[%d][%d] -> Expected: 10, Actual: %d\n",
                       i, j, dest2[i][j]);
                printf("--> NGUYEN NHAN PHO BIEN: AI chia co dinh cho 9 hoac quen dem so luong o lan can thuc te!\n");
                return 1;
            }
        }
    }

    // 4. Test ma trận 1 x 1
    int src3[100][MAX_COLS] = {{100}};
    int dest3[100][MAX_COLS] = {{0}};
    lamMoMaTran(src3, dest3, 1, 1);
    if (dest3[0][0] != 100) {
        printf("FAILED Test 3 (1x1): -> Expected: 100, Actual: %d\n", dest3[0][0]);
        return 1;
    }

    printf(">>> BAI 3: PASS 100%% TEST CASES!\n");
    return 0;
}
