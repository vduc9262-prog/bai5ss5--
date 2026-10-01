#include <stdio.h>

int main(void) {
    // Khai báo mảng số nguyên 1 chiều lưu chi phí khám bệnh với kích thước tối đa 10 phần tử
    int phi_kham[10] = {150000, 300000, 200000, 500000};
    int so_luong = 4; // Biến đếm số lượng phần tử thực tế trong mảng

    // Khai báo các biến phục vụ thao tác nhập liệu
    int vi_tri_sua, gia_tri_moi;
    int phi_kham_moi;
    int vi_tri_xoa;

    // 1. TÍNH TỔNG CHI PHÍ 2 CA KHÁM ĐẦU TIÊN
    int tong_chi_phi = phi_kham[0] + phi_kham[1];
    printf("Tong chi phi 2 ca dau: %d VND\n", tong_chi_phi);

    // 2. CẬP NHẬT (UPDATE) CHI PHÍ CA KHÁM THEO VỊ TRÍ
    printf("Nhap vi tri can sua (0 - %d): ", so_luong - 1);
    if (scanf("%d", &vi_tri_sua) != 1) {
        printf("Loi: Du lieu nhap khong hop le!\n");
        return 1;
    }

    printf("Nhap gia tri chi phi moi: ");
    if (scanf("%d", &gia_tri_moi) != 1) {
        printf("Loi: Du lieu nhap khong hop le!\n");
        return 1;
    }

    // Kiểm tra tính hợp lệ của vị trí sửa
    if (vi_tri_sua >= 0 && vi_tri_sua < so_luong) {
        phi_kham[vi_tri_sua] = gia_tri_moi;
        printf("Sau khi sua vi tri %d: Chi phi moi = %d VND\n", vi_tri_sua, phi_kham[vi_tri_sua]);
    } else {
        printf("Loi: Vi tri sua %d khong hop le!\n", vi_tri_sua);
    }

    // 3. THÊM MỚI (CREATE) CA KHÁM VÀO CỦỐI MẢNG
    printf("Nhap chi phi ca kham moi can them: ");
    if (scanf("%d", &phi_kham_moi) != 1) {
        printf("Loi: Du lieu nhap khong hop le!\n");
        return 1;
    }

    // Kiểm tra giới hạn dung lượng mảng trước khi thêm
    if (so_luong < 10) {
        phi_kham[so_luong] = phi_kham_moi;
        so_luong++; // Tăng biến đếm số lượng phần tử
        printf("Sau khi them ca moi: So luong = %d, Chi phi ca cuoi = %d VND\n", so_luong, phi_kham[so_luong - 1]);
    } else {
        printf("Loi: Mang da day, khong the them ca kham moi!\n");
    }

    // 4. XÓA (DELETE) CA KHÁM KHỎI MẢNG VÀ DỒN DỊCH
    printf("Nhap vi tri can xoa (0 - %d): ", so_luong - 1);
    if (scanf("%d", &vi_tri_xoa) != 1) {
        printf("Loi: Du lieu nhap khong hop le!\n");
        return 1;
    }

    // Kiểm tra điều kiện vị trí xóa hợp lệ trong khoảng [0, so_luong - 1]
    if (vi_tri_xoa >= 0 && vi_tri_xoa < so_luong) {
        // Thực hiện dồn dịch mảng thủ công sang trái (Hard Delete)
        for (int i = vi_tri_xoa; i < so_luong - 1; i++) {
            phi_kham[i] = phi_kham[i + 1];
        }
        
        so_luong--; // Giảm số lượng phần tử thực tế

        printf("Sau khi xoa vi tri %d: So luong = %d, Chi phi vi tri %d moi = %d VND\n", 
               vi_tri_xoa, so_luong, vi_tri_xoa, phi_kham[vi_tri_xoa]);
    } else {
        // Thông báo lỗi nếu vị trí xóa vượt quá phạm vi chỉ số
        printf("Loi: Vi tri xoa %d khong hop le!\n", vi_tri_xoa);
        printf("So luong ca kham giu nguyen: %d\n", so_luong);
    }

    return 0;
}