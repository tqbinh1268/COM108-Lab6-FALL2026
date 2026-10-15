#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define UNIT_TEST
#include "../src/bai2.c"

int kiemTraMangGiamDan(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1] - 0.0001) {
            return 0; // Vi phạm thứ tự giảm dần
        }
    }
    return 1;
}

int main() {
    printf("[CHAY TEST BAI 2: SAP XEP GIAM DAN]\n");

    // 1. Kiểm tra kiến trúc: Cấm dùng printf trong hàm sapXepGiamDan
    FILE *f = fopen("src/bai2.c", "r");
    if (f) {
        char line[256];
        int inHam = 0;
        while (fgets(line, sizeof(line), f)) {
            if (strstr(line, "SINH VIÊN VIẾT CODE")) inHam = 1;
            if (inHam && strstr(line, "printf")) {
                printf("FAILED Kien truc: Phat hien lenh 'printf' ben trong ham sapXepGiamDan!\n");
                printf("--> YEU CAU: Ham chi sap xep du lieu trong bo nho. In an phai thuc hien o main()!\n");
                fclose(f);
                return 1;
            }
        }
        fclose(f);
    }

    // 2. Test chuẩn: Mảng số dương cần đảo thứ tự
    float a1[] = {2.5, 9.0, 1.2, 7.8, 5.0};
    sapXepGiamDan(a1, 5);
    if (!kiemTraMangGiamDan(a1, 5) || fabs(a1[0] - 9.0) > 0.001 || fabs(a1[4] - 1.2) > 0.001) {
        printf("FAILED Test 1: Sap xep mang duong that bai!\n");
        printf("Actual: %.2f, %.2f, %.2f, %.2f, %.2f\n", a1[0], a1[1], a1[2], a1[3], a1[4]);
        return 1;
    }

    // 3. Test mảng có phần tử trùng nhau
    float a2[] = {4.0, 8.5, 4.0, 9.2, 8.5};
    sapXepGiamDan(a2, 5);
    if (!kiemTraMangGiamDan(a2, 5) || fabs(a2[0] - 9.2) > 0.001 || fabs(a2[4] - 4.0) > 0.001) {
        printf("FAILED Test 2: Mang co phan tu trung nhau that bai!\n");
        return 1;
    }

    // 4. Test mảng có cả số âm và số dương
    float a3[] = {-3.5, 2.0, -10.0, 0.0, 5.5};
    sapXepGiamDan(a3, 5);
    if (!kiemTraMangGiamDan(a3, 5) || fabs(a3[0] - 5.5) > 0.001 || fabs(a3[4] - (-10.0)) > 0.001) {
        printf("FAILED Test 3: Mang co so am va so 0 that bai!\n");
        printf("Expected dau: 5.50, cuoi: -10.00 | Actual dau: %.2f, cuoi: %.2f\n", a3[0], a3[4]);
        return 1;
    }

    // 5. Test mảng 1 phần tử
    float a4[] = {100.0};
    sapXepGiamDan(a4, 1);
    if (fabs(a4[0] - 100.0) > 0.001) {
        printf("FAILED Test 4: Mang 1 phan tu bi thay doi gia tri!\n");
        return 1;
    }

    printf(">>> BAI 2: PASS 100%% TEST CASES!\n");
    return 0;
}
