#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
void nenDelta(int goc[], int delta[], int n);
void giaiNenDelta(int delta[], int khoiPhuc[], int n);

#ifndef UNIT_TEST
int main() {
    int n;
    int goc[100], delta[100], khoiPhuc[100];

    printf("Nhap so luong gia tri do dac IoT (n > 0): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong khong hop le!\n");
        return 0;
    }

    printf("Nhap %d gia tri do dac ban dau:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  goc[%d] = ", i);
        scanf("%d", &goc[i]);
    }

    // 1. Nén dữ liệu
    nenDelta(goc, delta, n);

    printf("\n--- CHUOI DU LIEU NEN DELTA TRUYEN QUA MANG ---\n");
    for (int i = 0; i < n; i++) {
        if (i == 0) printf("%d ", delta[i]);
        else printf("%+d ", delta[i]);
    }
    printf("\n");

    // 2. Phía máy chủ giải nén
    giaiNenDelta(delta, khoiPhuc, n);

    printf("\n--- KET QUA GIAI NEN TAI MAY CHU ---\n");
    int khop = 1;
    for (int i = 0; i < n; i++) {
        printf("%d ", khoiPhuc[i]);
        if (khoiPhuc[i] != goc[i]) khop = 0;
    }
    printf("\n");

    if (khop) {
        printf(">> XAC THUC: Du lieu giai nen KHOP 100%% voi du lieu goc!\n");
    } else {
        printf(">> CANH BAO: Du lieu giai nen bi SAI LECH!\n");
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA 2 HÀM DƯỚI ĐÂY ---
void nenDelta(int goc[], int delta[], int n) {
    // TODO: Nén mảng goc[] thành mảng sai phân delta[]
    // - delta[0] = goc[0]
    // - Với i >= 1: delta[i] = goc[i] - goc[i-1]
    // LƯU Ý: Không dùng lệnh in ra màn hình bên trong hàm
    
}

void giaiNenDelta(int delta[], int khoiPhuc[], int n) {
    // TODO: Khôi phục mảng gốc từ mảng delta[]
    // - khoiPhuc[0] = delta[0]
    // - Với i >= 1: khoiPhuc[i] = khoiPhuc[i-1] + delta[i]
    // LƯU Ý: Không dùng lệnh in ra màn hình bên trong hàm
    
}
