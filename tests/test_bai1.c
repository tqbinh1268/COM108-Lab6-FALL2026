#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define UNIT_TEST
#include "../src/bai1.c"

int main() {
    printf("[CHAY TEST BAI 1: MAX/MIN CAM BIEN NHIET DO]\n");

    // 1. Kiểm tra kiến trúc: Cấm dùng printf trong hàm timMaxMin
    FILE *f = fopen("src/bai1.c", "r");
    if (f) {
        char line[256];
        int inHam = 0;
        while (fgets(line, sizeof(line), f)) {
            if (strstr(line, "SINH VIÊN VIẾT CODE")) inHam = 1;
            if (inHam && strstr(line, "printf")) {
                printf("FAILED Kien truc: Phat hien lenh 'printf' ben trong ham timMaxMin!\n");
                printf("--> YEU CAU: Ham chi tinh toan logic va gan ket qua vao con tro. Lenh in phai nam o main()!\n");
                fclose(f);
                return 1;
            }
        }
        fclose(f);
    }

    // 2. Test chuẩn: Mảng số dương bình thường
    float a1[] = {28.5, 32.0, 19.5, 40.2, 25.0};
    float max1 = 0, min1 = 0;
    int kq1 = timMaxMin(a1, 5, &max1, &min1);

    if (kq1 != 1) {
        printf("FAILED Test 1: Ham phai tra ve 1 khi mang hop le (n > 0)!\n");
        return 1;
    }
    if (fabs(max1 - 40.2) > 0.001 || fabs(min1 - 19.5) > 0.001) {
        printf("FAILED Test 1: Ket qua sai voi mang duong -> Expected: Max=40.20, Min=19.50 | Actual: Max=%.2f, Min=%.2f\n", max1, min1);
        return 1;
    }

    // 3. Test bẫy: Mảng toàn số âm (Bẫy lỗi sinh viên khởi tạo max = 0)
    float a2[] = {-15.5, -3.2, -40.0, -0.5, -8.0};
    float max2 = 0, min2 = 0;
    int kq2 = timMaxMin(a2, 5, &max2, &min2);

    if (kq2 != 1) {
        printf("FAILED Test 2: Ham phai tra ve 1 khi mang hop le (n > 0)!\n");
        return 1;
    }
    if (fabs(max2 - (-0.5)) > 0.001) {
        printf("FAILED Test 2: Tim sai Max voi mang so am -> Expected: -0.50, Actual: %.2f\n", max2);
        printf("--> NGUYEN NHAN PHO BIEN: Khoi tao max = 0 thay vi max = a[0]!\n");
        return 1;
    }
    if (fabs(min2 - (-40.0)) > 0.001) {
        printf("FAILED Test 2: Tim sai Min voi mang so am -> Expected: -40.00, Actual: %.2f\n", min2);
        return 1;
    }

    // 4. Test mảng 1 phần tử
    float a3[] = {12.5};
    float max3 = 0, min3 = 0;
    timMaxMin(a3, 1, &max3, &min3);
    if (fabs(max3 - 12.5) > 0.001 || fabs(min3 - 12.5) > 0.001) {
        printf("FAILED Test 3: Mang 1 phan tu -> Expected: Max=12.50, Min=12.50 | Actual: Max=%.2f, Min=%.2f\n", max3, min3);
        return 1;
    }

    // 5. Test mảng không hợp lệ (n <= 0)
    float max4 = 999, min4 = 999;
    int kq4 = timMaxMin(a1, 0, &max4, &min4);
    if (kq4 != 0) {
        printf("FAILED Test 4: Khi n <= 0, ham phai tra ve 0 de bao loi!\n");
        return 1;
    }

    printf(">>> BAI 1: PASS 100%% TEST CASES!\n");
    return 0;
}
