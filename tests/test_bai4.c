#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_TEST
#include "../src/bai4.c"

int main() {
    printf("[CHAY TEST BAI 4: RADAR DO DIEM NONG QUAN TRONG (PEAK DETECTION)]\n");

    // 1. Kiểm tra kiến trúc: Cấm dùng printf trong hàm doDiemNong
    FILE *f = fopen("src/bai4.c", "r");
    if (f) {
        char line[256];
        int inHam = 0;
        while (fgets(line, sizeof(line), f)) {
            if (strstr(line, "SINH VIÊN VIẾT CODE")) inHam = 1;
            if (inHam && strstr(line, "printf(")) {
                printf("FAILED Kien truc: Phat hien lenh 'printf' ben trong than ham doDiemNong!\n");
                printf("--> YEU CAU: Ham chi trich xuat du lieu vao cac mang ket qua. In an phai o main()!\n");
                fclose(f);
                return 1;
            }
        }
        fclose(f);
    }

    // 2. Test chuẩn: Điểm nóng ở giữa (tâm) ma trận 3 x 3
    int a1[100][MAX_COLS] = {
        {10, 20, 15},
        {25, 99, 30},
        {12, 18, 14}
    };
    int hang1[10], cot1[10], val1[10];
    int count1 = doDiemNong(a1, 3, 3, hang1, cot1, val1);

    if (count1 != 1) {
        printf("FAILED Test 1: Dem sai so luong diem nong -> Expected: 1, Actual: %d\n", count1);
        return 1;
    }
    if (hang1[0] != 1 || cot1[0] != 1 || val1[0] != 99) {
        printf("FAILED Test 1: Toa do hoac gia tri sai -> Expected a[1][1]=99, Actual a[%d][%d]=%d\n",
               hang1[0], cot1[0], val1[0]);
        return 1;
    }

    // 3. Test điểm nóng nằm ở góc (Corner Peak)
    int a2[100][MAX_COLS] = {
        {50, 20},
        {10,  5}
    };
    int hang2[10], cot2[10], val2[10];
    int count2 = doDiemNong(a2, 2, 2, hang2, cot2, val2);
    if (count2 != 1 || hang2[0] != 0 || cot2[0] != 0 || val2[0] != 50) {
        printf("FAILED Test 2 (Diem nong o goc): -> Expected a[0][0]=50, Actual count=%d\n", count2);
        return 1;
    }

    // 4. Test bẫy AI: Ma trận phẳng (Tất cả các ô bằng nhau)
    // Quy định: Phải lớn hơn NGHIÊM NGẶT (>), nên không ô nào là Peak.
    int a3[100][MAX_COLS] = {
        {30, 30},
        {30, 30}
    };
    int hang3[10], cot3[10], val3[10];
    int count3 = doDiemNong(a3, 2, 2, hang3, cot3, val3);
    if (count3 != 0) {
        printf("FAILED Test 3 (Bay AI ma tran phang): Expected: 0, Actual: %d\n", count3);
        printf("--> NGUYEN NHAN PHO BIEN: AI dung dau '>=' thay vi '>' nghiem ngat khien toan bo o bi nhan nham la Peak!\n");
        return 1;
    }

    // 5. Test ma trận nhiệt độ âm (Kho lạnh)
    int a4[100][MAX_COLS] = {
        {-50, -20, -50},
        {-60, -10, -70},
        {-50, -30, -50}
    };
    int hang4[10], cot4[10], val4[10];
    int count4 = doDiemNong(a4, 3, 3, hang4, cot4, val4);
    if (count4 != 1 || hang4[0] != 1 || cot4[0] != 1 || val4[0] != -10) {
        printf("FAILED Test 4 (So am kho lanh): -> Expected a[1][1]=-10, Actual count=%d\n", count4);
        return 1;
    }

    printf(">>> BAI 4: PASS 100%% TEST CASES!\n");
    return 0;
}
