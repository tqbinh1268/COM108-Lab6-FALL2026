#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define UNIT_TEST
#include "../src/bai1.c"

int main() {
    printf("[CHAY TEST BAI 1: BO LOC LAM MIN TIN HIEU MOVING AVERAGE]\n");

    // 1. Kiểm tra kiến trúc: Cấm dùng printf trong hàm lamMinTinHieu
    FILE *f = fopen("src/bai1.c", "r");
    if (f) {
        char line[256];
        int inHam = 0;
        while (fgets(line, sizeof(line), f)) {
            if (strstr(line, "SINH VIÊN VIẾT CODE")) inHam = 1;
            if (inHam && strstr(line, "printf(")) {
                printf("FAILED Kien truc: Phat hien lenh 'printf' ben trong ham lamMinTinHieu!\n");
                printf("--> YEU CAU: Ham chi tinh toan luu vao mang smooth[]. In an phai nam o main()!\n");
                fclose(f);
                return 1;
            }
        }
        fclose(f);
    }

    // 2. Test chuẩn: Mảng n = 5
    float raw1[] = {10.0, 20.0, 30.0, 40.0, 50.0};
    float smooth1[5] = {0};
    lamMinTinHieu(raw1, smooth1, 5);

    float exp1[] = {15.0, 20.0, 30.0, 40.0, 45.0};
    for (int i = 0; i < 5; i++) {
        if (fabs(smooth1[i] - exp1[i]) > 0.01) {
            printf("FAILED Test 1 (Chuan n=5): Tai vi tri smooth[%d] -> Expected: %.2f, Actual: %.2f\n",
                   i, exp1[i], smooth1[i]);
            return 1;
        }
    }

    // 3. Test bẫy AI biên: n = 1
    float raw2[] = {42.0};
    float smooth2[1] = {0};
    lamMinTinHieu(raw2, smooth2, 1);
    if (fabs(smooth2[0] - 42.0) > 0.01) {
        printf("FAILED Test 2 (Bay AI bien n=1): -> Expected: 42.00, Actual: %.2f\n", smooth2[0]);
        printf("--> NGUYEN NHAN: AI thuong quen kiem tra truong hop dac biet n = 1 dan den loi doc ngoai mang!\n");
        return 1;
    }

    // 4. Test bẫy AI biên: n = 2
    float raw3[] = {12.0, 28.0};
    float smooth3[2] = {0};
    lamMinTinHieu(raw3, smooth3, 2);
    if (fabs(smooth3[0] - 20.0) > 0.01 || fabs(smooth3[1] - 20.0) > 0.01) {
        printf("FAILED Test 3 (Bay AI bien n=2): -> Expected: {20.00, 20.00}, Actual: {%.2f, %.2f}\n",
               smooth3[0], smooth3[1]);
        return 1;
    }

    // 5. Test mảng có số âm
    float raw4[] = {-10.0, 5.0, -15.0, 20.0};
    float smooth4[4] = {0};
    lamMinTinHieu(raw4, smooth4, 4);
    float exp4[] = {-2.5, -6.6667, 3.3333, 2.5};
    for (int i = 0; i < 4; i++) {
        if (fabs(smooth4[i] - exp4[i]) > 0.01) {
            printf("FAILED Test 4 (So am): Tai vi tri smooth[%d] -> Expected: %.2f, Actual: %.2f\n",
                   i, exp4[i], smooth4[i]);
            return 1;
        }
    }

    printf(">>> BAI 1: PASS 100%% TEST CASES!\n");
    return 0;
}
