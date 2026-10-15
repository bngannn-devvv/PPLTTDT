#include <stdio.h>

/* ---------- NHOM 1: lam viec voi n ---------- */

// a) Liet ke cac uoc so cua n
void LietKeUoc(int n)
{
    int i;
    printf("a) Cac uoc so cua %d: ", n);
    for (i = 1; i <= n; i++)
        if (n % i == 0)
            printf("%d ", i);
    printf("\n");
}

// b) Tong cac so chan < n
int TongChan(int n)
{
    int i, s = 0;
    for (i = 2; i < n; i += 2)   // 2, 4, 6, ... nho hon n
        s = s + i;
    return s;
}

// c) Tong binh phuong cac so le < n
int TongBinhPhuongLe(int n)
{
    int i, s = 0;
    for (i = 1; i < n; i += 2)   // 1, 3, 5, ... nho hon n
        s = s + i * i;
    return s;
}

// d) Dem so luong so < n chia het cho ca 3 va 5
int DemBoi3Va5(int n)
{
    int i, dem = 0;
    for (i = 1; i < n; i++)
        if (i % 3 == 0 && i % 5 == 0)
            dem++;
    return dem;
}

// e) Kiem tra so nguyen to (tra ve 1 neu dung, 0 neu sai)
int LaSoNguyenTo(int n)
{
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i < n; i++)
        if (n % i == 0)
            return 0;            // co uoc khac 1 va n => khong phai
    return 1;
}

// f) Kiem tra so chinh phuong
int LaChinhPhuong(int n)
{
    int i;
    for (i = 1; i * i <= n; i++)
        if (i * i == n)
            return 1;
    return 0;
}

// h) Kiem tra so hoan thien (tong cac uoc < n bang chinh n)
int LaHoanThien(int n)
{
    int i, tong = 0;
    for (i = 1; i < n; i++)
        if (n % i == 0)
            tong = tong + i;
    if (tong == n && n > 1)
        return 1;
    return 0;
}

/* ---------- NHOM 2: lam viec voi cac chu so cua n ---------- */

// g) Dem so chu so cua n
int DemChuSo(int n)
{
    int dem = 0;
    while (n > 0)
    {
        dem++;
        n = n / 10;
    }
    return dem;
}

// i) Liet ke cac chu so chan cua n
void LietKeChuSoChan(int n)
{
    int cs;
    printf("i) Cac chu so chan (doc tu phai sang trai): ");
    while (n > 0)
    {
        cs = n % 10;             // lay chu so cuoi
        if (cs % 2 == 0)
            printf("%d ", cs);
        n = n / 10;              // bo chu so cuoi
    }
    printf("\n");
}

// 10) Kiem tra n co toan chu so chan khong
int ToanChuSoChan(int n)
{
    int cs;
    while (n > 0)
    {
        cs = n % 10;
        if (cs % 2 != 0)
            return 0;            // gap 1 chu so le la sai ngay
        n = n / 10;
    }
    return 1;
}

// 11) Tong cac chu so chan cua n
int TongChuSoChan(int n)
{
    int cs, s = 0;
    while (n > 0)
    {
        cs = n % 10;
        if (cs % 2 == 0)
            s = s + cs;
        n = n / 10;
    }
    return s;
}

// 12) Tim chu so lon nhat cua n
int ChuSoLonNhat(int n)
{
    int cs, max = n % 10;        // gia su chu so cuoi la lon nhat
    n = n / 10;
    while (n > 0)
    {
        cs = n % 10;
        if (cs > max)
            max = cs;
        n = n / 10;
    }
    return max;
}

// 13) Kiem tra n co doi xung khong
int LaDoiXung(int n)
{
    int goc = n, dao = 0, cs;
    while (goc > 0)
    {
        cs = goc % 10;
        dao = dao * 10 + cs;
        goc = goc / 10;
    }
    if (dao == n)
        return 1;
    return 0;
}

/* ---------- HAM MAIN ---------- */
int main()
{
    int n;

    do
    {
        printf("Nhap n (0 < n < 1000): ");
        scanf("%d", &n);
        if (n <= 0 || n >= 1000)   // them: || n % 2 != 0 neu de bat n chan
            printf("Sai roi, nhap lai!\n");
    } while (n <= 0 || n >= 1000); // sua dieu kien o day cho giong ben tren

    LietKeUoc(n);
    printf("b) Tong cac so chan < %d: %d\n", n, TongChan(n));
    printf("c) Tong binh phuong cac so le < %d: %d\n", n, TongBinhPhuongLe(n));
    printf("d) So luong so < %d chia het cho 3 va 5: %d\n", n, DemBoi3Va5(n));

    if (LaSoNguyenTo(n)) printf("e) %d la so nguyen to\n", n);
    else                 printf("e) %d khong phai so nguyen to\n", n);

    if (LaChinhPhuong(n)) printf("f) %d la so chinh phuong\n", n);
    else                  printf("f) %d khong phai so chinh phuong\n", n);

    printf("g) %d co %d chu so\n", n, DemChuSo(n));

    if (LaHoanThien(n)) printf("h) %d la so hoan thien\n", n);
    else                printf("h) %d khong phai so hoan thien\n", n);

    LietKeChuSoChan(n);

    if (ToanChuSoChan(n)) printf("10) %d toan chu so chan\n", n);
    else                  printf("10) %d khong toan chu so chan\n", n);

    printf("11) Tong cac chu so chan: %d\n", TongChuSoChan(n));
    printf("12) Chu so lon nhat: %d\n", ChuSoLonNhat(n));

    if (LaDoiXung(n)) printf("13) %d la so doi xung\n", n);
    else              printf("13) %d khong doi xung\n", n);

    return 0;
}
