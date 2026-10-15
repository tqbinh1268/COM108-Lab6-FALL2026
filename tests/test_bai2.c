#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_TEST
#include "../src/bai2.c"

int main() {
    printf("[CHAY TEST BAI 2: NEN & GIAI NEN SAI PHAN DELTA ENCODING]\n");

    // 1. Kiểm tra kiến trúc: Cấm dùng printf trong hàm nenDelta và giaiNenDelta
    FILE *f = fopen("src/bai2.c", "r");
    if (f) {
        char line[256];
        int inHam = 0;
        while (fgets(line, sizeof(line), f)) {
            if (strstr(line, "SINH VIÊN VIẾT CODE")) inHam = 1;
            if (inHam && strstr(line, "printf(")) {
                printf("FAILED Kien truc: Phat hien lenh 'printf' ben trong than ham nen/giai nen!\n");
                printf("--> YEU CAU: Ham chi thuc hien tinh toan du lieu tren bo nho. In an phai o main()!\n");
                fclose(f);
                return 1;
            }
        }
        fclose(f);
    }

    // 2. Test chuẩn: Chuỗi đo đạc nhiệt độ
    int goc1[] = {100, 103, 101, 105, 102};
    int delta1[5] = {0};
    int khoiPhuc1[5] = {0};

    nenDelta(goc1, delta1, 5);
    int expDelta1[] = {100, 3, -2, 4, -3};
    for (int i = 0; i < 5; i++) {
        if (delta1[i] != expDelta1[i]) {
            printf("FAILED Test Nen 1: delta[%d] -> Expected: %d, Actual: %d\n", i, expDelta1[i], delta1[i]);
            return 1;
        }
    }

    giaiNenDelta(delta1, khoiPhuc1, 5);
    for (int i = 0; i < 5; i++) {
        if (khoiPhuc1[i] != goc1[i]) {
            printf("FAILED Test Giai Nen 1: khoiPhuc[%d] -> Expected: %d, Actual: %d\n", i, goc1[i], khoiPhuc1[i]);
            return 1;
        }
    }

    // 3. Test mảng hằng số (Delta phải toàn 0 sau phần tử đầu)
    int goc2[] = {50, 50, 50, 50};
    int delta2[4] = {0};
    int khoiPhuc2[4] = {0};
    nenDelta(goc2, delta2, 4);
    if (delta2[0] != 50 || delta2[1] != 0 || delta2[2] != 0 || delta2[3] != 0) {
        printf("FAILED Test Nen 2 (Hang so): Cac gia tri sai phan tiep theo phai bang 0!\n");
        return 1;
    }
    giaiNenDelta(delta2, khoiPhuc2, 4);
    for (int i = 0; i < 4; i++) {
        if (khoiPhuc2[i] != 50) {
            printf("FAILED Test Giai Nen 2 (Hang so): Khong khuc phuc duoc gia tri 50 ban dau!\n");
            return 1;
        }
    }

    // 4. Test số âm và mảng biến thiên lớn
    int goc3[] = {-10, -15, -12, 0, 5};
    int delta3[5] = {0};
    int khoiPhuc3[5] = {0};
    nenDelta(goc3, delta3, 5);
    giaiNenDelta(delta3, khoiPhuc3, 5);
    for (int i = 0; i < 5; i++) {
        if (khoiPhuc3[i] != goc3[i]) {
            printf("FAILED Test 3 (So am & qua so 0): Khong khop tai vi tri [%d]! Expected: %d, Actual: %d\n",
                   i, goc3[i], khoiPhuc3[i]);
            return 1;
        }
    }

    // 5. Test mảng 1 phần tử
    int goc4[] = {99};
    int delta4[1] = {0};
    int khoiPhuc4[1] = {0};
    nenDelta(goc4, delta4, 1);
    giaiNenDelta(delta4, khoiPhuc4, 1);
    if (delta4[0] != 99 || khoiPhuc4[0] != 99) {
        printf("FAILED Test 4 (Mang 1 phan tu): Loi khi n = 1!\n");
        return 1;
    }

    printf(">>> BAI 2: PASS 100%% TEST CASES!\n");
    return 0;
}
