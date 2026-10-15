#include <stdio.h>
#define MAX 100

void NhapMang(int a[], int *n)
{
    do {
        printf("Nhap n (0 < n < 100): ");
        scanf("%d", n);
    } while (*n <= 0 || *n >= MAX);

    for (int i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Cau 1: tong cac so chan
int TongChan(int a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            s += a[i];
    return s;
}

// Cau 2: dem so le
int DemLe(int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 != 0)
            dem++;
    return dem;
}

// Cau 6: mang toan chan? (1 = co, 0 = khong)
int ToanChan(int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] % 2 != 0)
            return 0;
    return 1;
}

// Cau 7: mang tang dan? (cho phep bang nhau)
int TangDan(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return 0;
    return 1;
}

// Cau 8: mang doi xung?
int DoiXung(int a[], int n)
{
    for (int i = 0; i < n / 2; i++)
        if (a[i] != a[n - 1 - i])
            return 0;
    return 1;
}

// Cau 11: so lon nhat
int TimMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

// Cau 16: liet ke cac gia tri > x
void LietKeLonHonX(int a[], int n, int x)
{
    int co = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > x) {
            printf("%d ", a[i]);
            co = 1;
        }
    if (!co) printf("(khong co)");
    printf("\n");
}

// Cau 17: dem cac phan tu > x
int DemLonHonX(int a[], int n, int x)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > x)
            dem++;
    return dem;
}

// Cau 18: them y vao cuoi mang
void ThemCuoi(int a[], int *n, int y)
{
    if (*n < MAX) {
        a[*n] = y;
        (*n)++;
    } else
        printf("Mang day, khong them duoc!\n");
}

// Cau 21: xoa phan tu dau tien
void XoaDau(int a[], int *n)
{
    if (*n > 0) {
        for (int i = 0; i < *n - 1; i++)
            a[i] = a[i + 1];
        (*n)--;
    }
}

int main()
{
    int a[MAX], n, x, y;

    NhapMang(a, &n);
    printf("Mang: ");
    XuatMang(a, n);

    printf("Cau 1 - Tong chan: %d\n", TongChan(a, n));
    printf("Cau 2 - So luong le: %d\n", DemLe(a, n));
    printf("Cau 6 - %s\n", ToanChan(a, n) ? "Toan chan" : "Khong toan chan");
    printf("Cau 7 - %s\n", TangDan(a, n) ? "Tang dan" : "Khong tang dan");
    printf("Cau 8 - %s\n", DoiXung(a, n) ? "Doi xung" : "Khong doi xung");
    printf("Cau 11 - Max: %d\n", TimMax(a, n));

    printf("Nhap x: ");
    scanf("%d", &x);
    printf("Cau 16 - Cac gia tri > %d: ", x);
    LietKeLonHonX(a, n, x);
    printf("Cau 17 - Co %d phan tu > %d\n", DemLonHonX(a, n, x), x);

    printf("Nhap y: ");
    scanf("%d", &y);
    ThemCuoi(a, &n, y);
    printf("Cau 18 - Sau khi them y: ");
    XuatMang(a, n);

    XoaDau(a, &n);
    printf("Cau 21 - Sau khi xoa phan tu dau: ");
    XuatMang(a, n);

    return 0;
}
