#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_TEST
#include "../src/bai4.c"

int main() {
    printf("[CHAY TEST BAI 4: LOC SO LE MA TRAN]\n");

    // 1. Kiểm tra kiến trúc: Cấm dùng printf trong hàm locSoLeMaTran
    FILE *f = fopen("src/bai4.c", "r");
    if (f) {
        char line[256];
        int inHam = 0;
        while (fgets(line, sizeof(line), f)) {
            if (strstr(line, "SINH VIÊN VIẾT CODE")) inHam = 1;
            if (inHam && strstr(line, "printf")) {
                printf("FAILED Kien truc: Phat hien lenh 'printf' ben trong ham locSoLeMaTran!\n");
                printf("--> YEU CAU: Ham chi trich xuat du lieu vao cac mang ket qua. Lenh in phai nam o main()!\n");
                fclose(f);
                return 1;
            }
        }
        fclose(f);
    }

    // 2. Test chuẩn: Ma trận gồm cả số chẵn và lẻ dương
    int a1[100][MAX_COLS] = {
        {2, 5, 8},
        {11, 4, 7}
    };
    int hang1[10], cot1[10], val1[10];
    int count1 = locSoLeMaTran(a1, 2, 3, hang1, cot1, val1);

    if (count1 != 3) {
        printf("FAILED Test 1: Dem sai so luong so le -> Expected: 3, Actual: %d\n", count1);
        return 1;
    }
    // Thứ tự duyệt từ trên xuống dưới, trái qua phải: (0,1)=5, (1,0)=11, (1,2)=7
    if (hang1[0] != 0 || cot1[0] != 1 || val1[0] != 5) {
        printf("FAILED Test 1: Phan tu le thu nhat sai toa do -> Expected a[0][1]=5, Actual a[%d][%d]=%d\n",
               hang1[0], cot1[0], val1[0]);
        return 1;
    }
    if (hang1[1] != 1 || cot1[1] != 0 || val1[1] != 11) {
        printf("FAILED Test 1: Phan tu le thu hai sai toa do -> Expected a[1][0]=11, Actual a[%d][%d]=%d\n",
               hang1[1], cot1[1], val1[1]);
        return 1;
    }
    if (hang1[2] != 1 || cot1[2] != 2 || val1[2] != 7) {
        printf("FAILED Test 1: Phan tu le thu ba sai toa do -> Expected a[1][2]=7, Actual a[%d][%d]=%d\n",
               hang1[2], cot1[2], val1[2]);
        return 1;
    }

    // 3. Test bẫy: Số lẻ âm (Bẫy kinh điển % 2 == 1 vs % 2 != 0)
    int a2[100][MAX_COLS] = {
        {-4, -3},
        {2, -7}
    };
    int hang2[10], cot2[10], val2[10];
    int count2 = locSoLeMaTran(a2, 2, 2, hang2, cot2, val2);

    if (count2 != 2) {
        printf("FAILED Test 2: Khong loc duoc so le am -> Expected: 2, Actual: %d\n", count2);
        printf("--> NGUYEN NHAN PHO BIEN: Dung dieu kien '%% 2 == 1' thay vi '%% 2 != 0' (trong C, -3 %% 2 bang -1)!\n");
        return 1;
    }
    if (val2[0] != -3 || val2[1] != -7) {
        printf("FAILED Test 2: Gia tri so le am sai -> Actual: %d, %d\n", val2[0], val2[1]);
        return 1;
    }

    // 4. Test ma trận không có số lẻ nào (toàn số chẵn)
    int a3[100][MAX_COLS] = {
        {2, 4},
        {6, 8}
    };
    int hang3[10], cot3[10], val3[10];
    int count3 = locSoLeMaTran(a3, 2, 2, hang3, cot3, val3);

    if (count3 != 0) {
        printf("FAILED Test 3: Ma tran toan so chan nhung ham lai tra ve count = %d (Expected: 0)!\n", count3);
        return 1;
    }

    printf(">>> BAI 4: PASS 100%% TEST CASES!\n");
    return 0;
}
