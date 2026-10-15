# YÊU CẦU LAB 6 - COM108 (PHIÊN BẢN NÂNG CẤP KỶ NGUYÊN AI - 2026)

> [!NOTE] 
> **Môn học:** Nhập môn Lập trình với C (PRF192 / COM108)  
> **Chủ đề:** Mảng 1 chiều & Mảng 2 chiều (Ma trận) trong Kỹ thuật Thực tế  
> **Thời lượng:** Thực hiện trong buổi học  
> **Hình thức nộp bài:** Sử dụng GitHub Template, đẩy mã nguồn (`git push`) và tự động kiểm thử CI/CD.

---

## PHẦN 1: HƯỚNG DẪN BẮT ĐẦU VÀ NỘP BÀI

### 1. Tải kho bài tập về máy (Clone)
1. Truy cập vào **Repository Template**: [COM108-Lab6-FALL2026](https://github.com/tqbinh1268/COM108-Lab6-FALL2026).
2. Nhấn nút màu xanh **"Use this template"** $\rightarrow$ **"Create a new repository"**.
3. Thiết lập: **Repository name:** `COM108-Lab6-<MaSinhVien>` | **Visibility:** `Public` $\rightarrow$ Bấm **Create repository**.
4. Lấy link HTTPS và chạy lệnh Terminal:
```bash
git clone <link_https_vua_copy>
cd COM108-Lab6-<MaSinhVien>
```

### 2. Quy trình làm từng bài & Đẩy lên GitHub (Push)

> [!TIP]
> **Quy trình chuẩn:** Hoàn thiện code → Test cục bộ → Push & Xem kết quả CI/CD → Xanh mới chuyển sang Bài tiếp theo (Nếu Đỏ: xem chi tiết lỗi, cập nhật Logbook và sửa code).

#### Bước 1: Code và Tự Kiểm Thử Cục Bộ
1. Viết code hoàn thiện các hàm trong file `.c` (nằm trong thư mục `src/`).
2. Tự chạy kiểm thử nhanh trên máy cá nhân trước khi nộp:
   ```bash
   # Ví dụ: Tự kiểm thử Bài 1
   gcc -Wall tests/test_bai1.c -o run_test1 -lm && ./run_test1
   ```
3. Cập nhật ghi chú vào `LOGBOOK.md`:
   * **Khi nộp lần đầu của một bài (Lần 1, 4, 7, 10):**
     * *Trạng thái:* Ghi `Chờ chấm`.
     * *Prompt hỏi AI (nếu có):* Dán câu lệnh/prompt đã dùng để hỏi AI (nếu tự viết thì ghi: *"Tự làm không dùng AI"*).
     * *Lỗi / Cách sửa:* Để trống hoặc ghi *"Chờ phản hồi CI/CD"*.
   * **Khi nộp sửa lỗi (sau khi CI/CD báo FAILED):**
     * *Trạng thái:* Ghi `Sửa lỗi lần 2` (hoặc `lần 3`).
     * *Lỗi phát hiện:* Ghi ngắn gọn lỗi từ bảng Dashboard (VD: *"Rớt Test 2 với n=1 do đọc tràn mảng"*).
     * *Cách sửa:* Ghi giải pháp đã sửa trong code (VD: *"Bổ sung if (n == 1) smooth[0] = raw[0]"*).

> [!NOTE]
> **VÍ DỤ MINH HỌA GHI `LOGBOOK.md` ĐẠT CHUẨN:**
> 
> *Trường hợp nộp lần đầu (Lần 1 - Bài 1):*
> ```markdown
> ### Lần 1: Bài 1 - Bộ Lọc Làm Mịn Tín Hiệu (Moving Average)
> - Trạng thái: Chờ chấm
> - Prompt hỏi AI (nếu có): "Viết hàm lọc trung bình trượt cửa sổ k=3 cho mảng float trong C..."
> - Lỗi phát hiện qua Test (nếu có): Chưa có
> - Cách sửa / Bài học: Chờ kết quả phản hồi từ GitHub Actions
> ```
> 
> *Trường hợp nộp sửa lỗi (Lần 2 - Bài 1 sau khi bị FAILED):*
> ```markdown
> ### Lần 2: Bài 1
> - Trạng thái: Sửa lỗi lần 2
> - Lỗi / Cách sửa: FAILED Test 2 do trường hợp biên n=1 bị đọc tràn mảng raw[-1]. Đã sửa bằng cách thêm điều kiện if (n == 1) smooth[0] = raw[0];
> ```

4. Chạy lệnh nộp bài lên GitHub:
```bash
git add src LOGBOOK.md
git commit -m "Nop bai 1: Hoan thanh Moving Average Filter"
git push origin main
```

#### Bước 2: Xem Bảng Kết Quả Tự Động (GitHub Step Summary)
Ngay sau khi push, truy cập vào tab **Actions** trên repo GitHub của bạn $\rightarrow$ bấm vào lần chạy kiểm thử mới nhất để xem bảng điều khiển:
* ✅ **Nếu bài làm PASS (Xanh):** Bạn đã vượt qua 100% test case bài này! Không cần push lại, hãy bắt tay làm ngay bài tiếp theo.
* ❌ **Nếu bài làm FAILED (Đỏ):** 
  1. Nhấp mở mục **"Chi tiết kiểm thử Bài X"** ngay trên bảng để đọc nguyên nhân lỗi.
  2. Ghi nhận lỗi và giải pháp vào `LOGBOOK.md`.
  3. Sửa code trong `src/` trên máy tính rồi push lại (Lần 2).
* 📈 **Tiến độ hạn ngạch:** Bảng tổng kết hiển thị trực tiếp số lượt commit đã sử dụng (tối đa 13 lượt).

---

### Bảng tra cứu hành động

| Biểu tượng | Trạng thái | Hành động tiếp theo |
| :---: | --- | --- |
| 🟡 | **Đang chấm** | Đợi 15 – 30 giây rồi tải lại trang. |
| ✅ | **PASS** | Ghi nhận vào `LOGBOOK.md` $\rightarrow$ Làm bài tiếp theo. |
| ❌ | **FAILED** | Mở bảng tóm tắt đọc log lỗi $\rightarrow$ Ghi nhận lỗi vào `LOGBOOK.md` $\rightarrow$ Sửa code $\rightarrow$ Push lại. |
| ⛔ | **QUOTA EXCEEDED** | Vượt quá 13 lần push. Hệ thống khóa tự động kiểm thử. Liên hệ giảng viên. |

---

## PHẦN 2: NỘI DUNG CHI TIẾT CÁC BÀI TẬP

### Quy định lập trình trong Kỷ nguyên AI

> [!IMPORTANT]
> **TƯ DUY KỶ NGUYÊN AI: SINH VIÊN LÀ TECH LEAD & CODE REVIEWER**  
> * Bạn **được phép** sử dụng các công cụ AI (ChatGPT, Claude, Cursor, Copilot) để hỗ trợ phân tích và gợi ý code.
> * Bạn **bắt buộc phải đọc hiểu từng dòng code** do AI sinh ra, tự tay kiểm tra tính đúng đắn và sửa chữa trước khi nộp.
> * Mỗi lần push, hãy ghi lại câu prompt đã hỏi AI và lỗi phát sinh (nếu có) vào `LOGBOOK.md`.

* **Quy tắc bất biến:**
  * Không thay đổi tên hàm, kiểu dữ liệu trả về và danh sách tham số trong các file mẫu (`src/bai1.c` đến `bai4.c`).
  * **Cấm biến toàn cục (`global variables`):** Toàn bộ dữ liệu trao đổi giữa các hàm phải qua tham số hoặc `return`.
  * **Tách bạch tính toán và hiển thị:** Mọi thao tác nhập xuất dữ liệu (`printf`, `scanf`) thực hiện tại `main()`. Hàm tính toán logic tuyệt đối không chứa lệnh `printf`.
  * **Chống gian lận (Anti-Tampering):** Sinh viên chỉ được commit sửa đổi các file trong thư mục `src/` và file `LOGBOOK.md`. **Mọi hành vi tự ý sửa đổi file trong `.github/workflows/` (nhằm tăng quota) hoặc sửa đổi file trong `tests/` đều bị coi là gian lận học thuật và nhận điểm 0 toàn bộ bài Lab.**

> [!WARNING]
> **Hạn ngạch đẩy bài (Luật 13-Push):** Toàn bộ bài Lab 6 được cấp tối đa **13 lần push**.
> * **Bài 1:** Tối đa 3 lần push.
> * **Bài 2:** Tối đa 3 lần push.
> * **Bài 3:** Tối đa 3 lần push.
> * **Bài 4:** Tối đa 4 lần push (dành thêm 1 lần do thuật toán quét lân cận phức tạp hơn).
> * *Hệ thống sẽ tự động khóa kiểm tra nếu vượt quá hạn ngạch.*

---

## CHI TIẾT 4 BÀI TẬP LAB 6

### Bài 1: Bộ Lọc Làm Mịn Tín Hiệu Nhiễu Cảm Biến (`src/bai1.c`)
* **Bối cảnh:** Cảm biến đo đạc nhiệt độ/dòng điện của trạm sạc gửi về chuỗi tín hiệu `float raw[]` ($n > 0$) nhưng luôn bị giật nhiễu xung do sóng điện từ. Cần tính mảng đã làm mịn `float smooth[]` bằng thuật toán **Trung bình trượt (Moving Average)** cửa sổ kích thước $k=3$.
* **Interface bắt buộc:**
  ```c
  void lamMinTinHieu(float raw[], float smooth[], int n);
  ```
* **Quy tắc xử lý biên:**
  * Nếu $n = 1$: `smooth[0] = raw[0]`
  * Với $n \ge 2$:
    * Tại ô đầu mút ($i = 0$): `smooth[0] = (raw[0] + raw[1]) / 2.0f;`
    * Tại ô cuối ($i = n - 1$): `smooth[n - 1] = (raw[n - 2] + raw[n - 1]) / 2.0f;`
    * Tại các ô giữa ($1 \le i \le n - 2$): `smooth[i] = (raw[i - 1] + raw[i] + raw[i + 1]) / 3.0f;`
* **Lưu ý:** Tuyệt đối không đọc tràn mảng ngoài chỉ số $[0 .. n-1]$ (như `raw[-1]` hay `raw[n]`).

---

### Bài 2: Nén & Giải Nén Sai Phân Dữ Liệu IoT (`src/bai2.c`)
* **Bối cảnh:** Để tiết kiệm băng thông truyền tin qua mạng viễn thông 4G/LoRa, thiết bị IoT không gửi chuỗi số nguyên đo đạc ban đầu `goc[]` ($n > 0$), mà chỉ gửi giá trị đầu tiên kèm mảng sai phân `delta[]` biểu diễn độ tăng giảm. Phía máy chủ sẽ thực hiện giải nén khôi phục lại dữ liệu gốc.
* **Interface bắt buộc:**
  ```c
  void nenDelta(int goc[], int delta[], int n);
  void giaiNenDelta(int delta[], int khoiPhuc[], int n);
  ```
* **Quy tắc thuật toán:**
  * **Hàm nén:**
    * `delta[0] = goc[0];`
    * Với $i \ge 1$: `delta[i] = goc[i] - goc[i - 1];`
  * **Hàm giải nén:**
    * `khoiPhuc[0] = delta[0];`
    * Với $i \ge 1$: `khoiPhuc[i] = khoiPhuc[i - 1] + delta[i];`
* **Xác thực:** Chuỗi sau giải nén phải khớp 100% từng giá trị với chuỗi ban đầu.

---

### Bài 3: Bộ Lọc Làm Mờ Điểm Ảnh Số (Box Blur Filter 3x3) (`src/bai3.c`)
* **Bối cảnh:** Lưới cảm biến quang học 2 chiều ghi nhận ma trận điểm ảnh $row \times col$ (`int src[][MAX_COLS]`). Để loại bỏ vết nhiễu hạt, ta áp dụng bộ lọc làm mờ ảnh (Box Blur 3x3) - nguyên lý nền tảng của kỹ thuật Tích chập (Convolution) trong Computer Vision.
* **Interface bắt buộc:**
  ```c
  #define MAX_COLS 100
  void lamMoMaTran(int src[][MAX_COLS], int dest[][MAX_COLS], int row, int col);
  ```
* **Quy tắc thuật toán:**
  * Với mỗi ô tại tọa độ $(i, j)$: xét cửa sổ $3 \times 3$ gồm các ô $(r, c)$ với $i - 1 \le r \le i + 1$ và $j - 1 \le c \le j + 1$.
  * **Chỉ cộng các ô hợp lệ nằm trong ma trận** ($0 \le r < row$ và $0 \le c < col$).
  * `dest[i][j] = tong_cac_o_hop_le / so_luong_o_hop_le;` (phép chia nguyên).
* **Lưu ý kỹ thuật:** Các ô ở 4 góc chỉ có 4 ô lân cận hợp lệ, các ô ở mép biên có 6 ô lân cận, các ô ở ruột có 9 ô (cần đếm chính xác số ô lân cận thực tế để chia trung bình, tránh đọc tràn mảng).

---

### Bài 4: Radar Dò Điểm Nóng Quá Nhiệt (Thermal Peak Detection) (`src/bai4.c`)
* **Bối cảnh:** Hệ thống radar giám sát nhiệt độ của khối pin lithium theo lưới ma trận $row \times col$ (`int a[][MAX_COLS]`). Cần xác định chính xác các **"Điểm nóng bất thường (Peak)"** có nguy cơ phát hỏa.
* **Interface bắt buộc:**
  ```c
  #define MAX_COLS 100
  int doDiemNong(int a[][MAX_COLS], int row, int col, int hangPeak[], int cotPeak[], int nhietDoPeak[]);
  ```
* **Định nghĩa Điểm nóng (Peak):**
  * Một ô $(i, j)$ được gọi là Điểm nóng nếu giá trị của nó **LỚN HƠN NGHIÊM NGẶT (`>`)** tất cả các ô lân cận trực tiếp theo 4 hướng (trên, dưới, trái, phải) tồn tại trong ma trận.
  * Nếu ô nằm ở biên hoặc góc thì chỉ so sánh với các ô lân cận thực tế tồn tại.
* **Nhiệm vụ:** Lưu chỉ số hàng vào `hangPeak[]`, cột vào `cotPeak[]`, nhiệt độ vào `nhietDoPeak[]`. Trả về tổng số lượng điểm nóng tìm thấy.
* **Lưu ý kỹ thuật:** Nếu ma trận phẳng (tất cả các ô bằng nhau), số lượng điểm nóng phải bằng `0` (phải lớn hơn nghiêm ngặt `>`). Xử lý đúng cho cả trường hợp nhiệt độ âm (kho lạnh).
