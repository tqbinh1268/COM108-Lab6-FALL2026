# YÊU CẦU LAB 6 - COM108 (CẬP NHẬT 2026)

> [!NOTE] 
> **Môn học:** Nhập môn Lập trình với C (PRF192 / COM108)  
> **Chủ đề:** Mảng 1 chiều & Mảng 2 chiều (Ma trận)  
> **Thời lượng:** Thực hiện trong buổi học  
> **Hình thức nộp bài:** Sử dụng GitHub Template, đẩy mã nguồn (`git push`) và tự động kiểm thử CI/CD.

---

## PHẦN 1: HƯỚNG DẪN BẮT ĐẦU VÀ NỘP BÀI (QUY TRÌNH MỚI)

### 1. Tải kho bài tập về máy (Clone)
1. Truy cập vào **đường link Repository** giảng viên cấp: [COM108-Lab6-FALL2026](https://github.com/tqbinh1268/COM108-Lab6-FALL2026).
2. Nhấn nút màu xanh **"Use this template"** $\rightarrow$ **"Create a new repository"**.
3. Thiết lập: **Repository name:** `COM108-Lab6-<MaSinhVien>` | **Visibility:** `Public` $\rightarrow$ Bấm **Create repository**.
4. Lấy link HTTPS và chạy lệnh Terminal:
```bash
git clone <link_https_vua_copy>
cd COM108-Lab6-<MaSinhVien>
```

### 2. Quy trình làm từng bài & Đẩy lên GitHub (Push)

> [!TIP]
> Thực hiện tuần tự: **Hoàn thiện Bài 1 $\rightarrow$ Push & Nhận trạng thái $\rightarrow$ Ghi log $\rightarrow$ Xanh mới chuyển sang Bài 2.**

#### Bước 1: Code và Ghi Log
1. Viết code hoàn thiện các hàm trong file `.c` (nằm trong thư mục `src/`).
2. Tự kiểm thử nhanh trên máy cá nhân:
   ```bash
   # Ví dụ kiểm thử Bài 1
   gcc -Wall tests/test_bai1.c -o run_test1 -lm && ./run_test1
   ```
3. Ghi nhật ký vào `LOGBOOK.md` trước khi push.
4. Chạy lệnh nộp bài:
```bash
git add src LOGBOOK.md
git commit -m "Nop bai 1: Hoan thanh tim Max Min"
git push origin main
```

#### Bước 2: Đọc trạng thái phản hồi từ GitHub
Ngay sau khi push, tải lại trang GitHub cá nhân:
* 🟡 **Đang chấm:** Đợi 15 – 30 giây.
* ✅ **Đạt (Pass):** Cập nhật `LOGBOOK.md` thành "Xanh", chuyển sang bài tiếp theo.
* ❌ **Lỗi (Failed):** 
  1. Bấm vào biểu tượng ❌ $\rightarrow$ **Details** đọc lỗi cụ thể.
  2. Ghi lỗi vào `LOGBOOK.md`.
  3. Sửa code trên máy rồi push lại.

---

### Bảng tra cứu hành động

| Trạng thái | Ý nghĩa | Hành động tiếp theo |
| :---: | --- | --- |
| 🟡 | **Đang chấm** | Đợi 15 – 30s rồi F5 lại trang. |
| ✅ | **Pass** | Ghi Log "Xanh" $\rightarrow$ Làm bài tiếp theo. |
| ❌ | **Failed** | Bấm **Details** đọc lỗi $\rightarrow$ Ghi Log lỗi $\rightarrow$ Sửa code $\rightarrow$ Push lại. |
| ⛔ | **QUOTA EXCEEDED** | Khóa nộp bài do push quá 12 lần. Báo cáo giảng viên. |

---

## PHẦN 2: NỘI DUNG CHI TIẾT CÁC BÀI TẬP

### Quy tắc làm bài bắt buộc

> [!IMPORTANT]
> **QUY TẮC BẤT BIẾN:** Tuyệt đối không thay đổi tên hàm, kiểu dữ liệu trả về và danh sách tham số trong các file mẫu (`src/bai1.c`, `bai2.c`, `bai3.c`, `bai4.c`).

* **Quy định lập trình:**
  * Được phép sử dụng AI (Cursor, Copilot, ChatGPT, Claude...) để hỗ trợ phân tích và viết code.
  * **Cấm biến toàn cục (`global variables`):** Toàn bộ dữ liệu trao đổi giữa các hàm phải thông qua tham số hoặc giá trị trả về (`return`).
  * **Tách bạch tính toán và hiển thị:** Mọi thao tác nhập xuất dữ liệu (`printf`, `scanf`) thực hiện tại `main()`. Hàm tính toán logic chỉ nhận mảng/kích thước và trả kết quả.

> [!WARNING]
> **Hạn ngạch đẩy bài (Luật 12-Push):** Toàn bộ bài Lab 6 được cấp tối đa **12 lần push**.
> * **Bài 1:** Tối đa 3 lần push.
> * **Bài 2:** Tối đa 3 lần push.
> * **Bài 3:** Tối đa 3 lần push.
> * **Bài 4:** Tối đa 3 lần push.
> * *Hệ thống CI/CD sẽ tự động khóa kiểm tra nếu commit vượt quá hạn ngạch quy định.*
> * *Mỗi lần đẩy bài (`push`) bắt buộc phải ghi nhận vào tệp `LOGBOOK.md`.*

---

## YÊU CẦU LAB 6

#### Bài 1: Module Giám Sát Cảm Biến Nhiệt Độ Trạm Sạc (`src/bai1.c`)
Một trạm sạc xe điện thông minh trang bị $n$ cảm biến nhiệt độ ($n > 0$) để đo đạc nhiệt độ pin và đầu sạc (độ Celsius, số thực `float`).
* **Hàm `timMaxMin`:**
  ```c
  int timMaxMin(float a[], int n, float *maxVal, float *minVal);
  ```
  * Nhận mảng `a[]` và số lượng phần tử `n`.
  * Tìm giá trị nhiệt độ cao nhất gán vào `*maxVal`, nhiệt độ thấp nhất gán vào `*minVal`.
  * Trả về `1` nếu xử lý thành công ($n > 0$), trả về `0` nếu dữ liệu không hợp lệ ($n \le 0$).
* **Tại hàm `main()`:** Nhập $n$, nhập từng giá trị cảm biến, gọi hàm và in kết quả ra màn hình.
* **Bẫy kiểm thử:** Hãy cẩn thận khi khởi tạo giá trị ban đầu cho `max` và `min` (tránh bẫy khi toàn bộ nhiệt độ đo được là số âm).

#### Bài 2: Hệ Thống Bảng Xếp Hạng Hiệu Suất Vận Hành Giảm Dần (`src/bai2.c`)
Hệ thống quản lý cần sắp xếp bảng điểm đánh giá hiệu suất của $n$ thiết bị trạm sạc theo thứ tự ưu tiên từ cao xuống thấp (giảm dần).
* **Hàm `sapXepGiamDan`:**
  ```c
  void sapXepGiamDan(float a[], int n);
  ```
  * Nhận mảng số thực `a[]` gồm `n` phần tử.
  * Sắp xếp các phần tử trực tiếp trên mảng sao cho $a[0] \ge a[1] \ge \dots \ge a[n-1]$ (dùng thuật toán Hoán đổi trực tiếp, Nổi bọt hoặc Chọn).
* **Tại hàm `main()`:** Nhập $n$, nhập mảng, gọi hàm sắp xếp và in mảng sau khi sắp xếp theo định dạng: `a[0] = [gia tri], a[1] = [gia tri], ...`
* **Lưu ý:** Tuyệt đối không dùng lệnh in (`printf`) bên trong hàm `sapXepGiamDan`.

#### Bài 3: Khuếch Đại Ma Trận Điểm Ảnh Cảm Biến Quang Học (`src/bai3.c`)
Hệ thống camera quét bề mặt ghi nhận lưới cảm biến quang học 2 chiều kích thước $row \times col$ ($row > 0, col > 0, \le 100$). Để tăng độ tương phản chi tiết, cần tính ma trận bình phương của từng điểm ảnh.
* **Hàm `maTranBinhPhuong`:**
  ```c
  void maTranBinhPhuong(int src[][MAX_COLS], int dest[][MAX_COLS], int row, int col);
  ```
  * Duyệt qua 2 chiều ma trận nguồn `src`, tính bình phương từng phần tử ($src[i][j]^2$) và lưu sang ma trận đích `dest`.
  * Giữ nguyên dữ liệu của ma trận nguồn `src`.
* **Tại hàm `main()`:** Nhập kích thước $row \times col$, nhập ma trận, gọi hàm và in ma trận kết quả dạng lưới (mỗi hàng trên một dòng, các phần tử cách nhau bởi dấu cách).

#### Bài 4: Rà Soát Tọa Độ Điểm Bất Thường Trên Lưới Cảm Biến (`src/bai4.c`)
Để phát hiện sớm các xung điện bất thường trên lưới cảm biến kích thước $row \times col$, module giám sát cần quét và trích xuất tất cả các ô có giá trị là **số lẻ**.
* **Hàm `locSoLeMaTran`:**
  ```c
  int locSoLeMaTran(int a[][MAX_COLS], int row, int col, int hangLe[], int cotLe[], int giaTriLe[]);
  ```
  * Duyệt ma trận `a` theo từng hàng và cột.
  * Khi phát hiện phần tử lẻ (chú ý: xử lý đúng cho cả số lẻ âm), ghi chỉ số hàng vào `hangLe[]`, chỉ số cột vào `cotLe[]`, và giá trị vào `giaTriLe[]`.
  * Trả về tổng số lượng phần tử lẻ tìm thấy.
* **Tại hàm `main()`:** 
  * Nếu không có phần tử lẻ nào: In `Khong co phan tu le trong ma tran.`
  * Nếu có: In danh sách theo đúng mẫu chuẩn:
    ```
    Phan tu le tai a[1][2] = 5
    ```

> [!CAUTION]
> **Lưu ý kỹ thuật cho Bài 4:** Trong ngôn ngữ C, `-3 % 2` bằng `-1`. Do đó, điều kiện kiểm tra số lẻ phải là `a[i][j] % 2 != 0` thay vì `a[i][j] % 2 == 1` để không bị bỏ sót các số lẻ mang giá trị âm!
