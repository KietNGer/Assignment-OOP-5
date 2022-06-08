#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
#define PI 3.14159265
using namespace std;
typedef long long ll;

class Point
{
private:
    double HoanhDo;
    double TungDo;
public:
    Point();
    Point(double a, double b);
    ~Point();
    Point Nhap();
    Point Tinh_tien(Point &P, int a, int b);
    int Lay_hoang_do();
    int Lay_tung_do();
    void Xuat(Point a);
    Point Quay(Point &a, Point &b, double angel);
    friend class TamGiac;
};

class TamGiac
{
private:
    Point a;
    Point b;
    Point c;
public:
    TamGiac();
    TamGiac(Point a, Point b, Point c);
    ~TamGiac();
    TamGiac(const TamGiac &T);
    TamGiac Nhap(TamGiac &T);
    TamGiac Tinh_tien(TamGiac &T, int a, int b);
    TamGiac Quay(TamGiac T, double angel);
    TamGiac ThuPhong(TamGiac &T, double k);
    void Xuat(TamGiac T);
};

Point ::Point()
{
    HoanhDo = 0;
    TungDo = 0;
}

Point ::Point(double a, double b)
{
    HoanhDo = a;
    TungDo = b;
}

Point ::~Point()
{
    HoanhDo = 0;
    TungDo = 0;
}

Point Point ::Nhap()
{
    Point a(0, 0);
    cout << "Nhap hoanh do: ";
    cin >> a.HoanhDo;
    cout << "Nhap tung do: ";
    cin >> a.TungDo;
    return a;
}

void Point ::Xuat(Point a)
{
    cout << "<" << a.HoanhDo << "," << a.TungDo << ">" << endl;
}

int Point ::Lay_hoang_do()
{
    return HoanhDo;
}

int Point ::Lay_tung_do()
{
    return TungDo;
}

Point Point ::Tinh_tien(Point &P, int a, int b)
{
    P.HoanhDo += a;
    P.TungDo += b;
    return P;
}

Point Point ::Quay(Point &a, Point &b, double angel)
{
    Point c(0, 0);
    c.HoanhDo = (a.HoanhDo - b.HoanhDo) * cos(angel) + (a.TungDo - b.TungDo) * sin(angel) + b.HoanhDo;
    c.TungDo = (a.HoanhDo - b.HoanhDo) * sin(angel) + (a.TungDo - b.TungDo) * cos(angel) + b.TungDo;
    return c;
}

TamGiac ::TamGiac()
{
    a = b = c = Point(0, 0);
}

TamGiac ::TamGiac(const TamGiac &T)
{
    a.HoanhDo = T.a.HoanhDo;
    b.HoanhDo = T.b.HoanhDo;
    c.HoanhDo = T.c.HoanhDo;
    a.TungDo = T.a.TungDo;
    b.TungDo = T.b.TungDo;
    c.TungDo = T.c.TungDo;
}


TamGiac ::TamGiac(Point d, Point e, Point f)
{
    a = d;
    b = e;
    c = f;
}

TamGiac ::~TamGiac()
{
    a = b = c = Point(0, 0);
}

TamGiac TamGiac ::Nhap(TamGiac &T)
{
    T.a = T.a.Nhap();
    T.b = T.b.Nhap();
    T.c = T.c.Nhap();
    return T;
}

void TamGiac ::Xuat(TamGiac T)
{
    cout << "Toa do tam giac lan luot la: \n";
    T.a.Xuat(T.a);
    T.b.Xuat(T.b);
    T.c.Xuat(T.c);
}

TamGiac TamGiac ::Tinh_tien(TamGiac &T, int d, int e)
{
    T.a = T.a.Tinh_tien(T.a, d, e);
    T.b = T.b.Tinh_tien(T.b, d, e);
    T.c = T.c.Tinh_tien(T.c, d, e);
    return T;
}

TamGiac TamGiac::Quay(TamGiac D, double angel)
{
        Point O(0, 0);
        D.a = D.a.Quay(D.a,O,angel);
        D.b = D.b.Quay(D.b,O,angel);
        D.c = D.c.Quay(D.c,O,angel);
        return D;
    }

TamGiac TamGiac ::ThuPhong(TamGiac &T, double k)
{
    T.a.HoanhDo *= k;
    T.b.HoanhDo *= k;
    T.c.HoanhDo *= k;
    T.a.TungDo *= k;
    T.b.TungDo *= k;
    T.c.TungDo *= k;
    return T;
}
int main()
{
    TamGiac T;
    T.Nhap(T);
    cout << "\nNhap toa do de tinh tien tam giac: ";
    int d, e;
    cin >> d >> e;
    TamGiac A(T);
    A.Xuat(A.Tinh_tien(T, d, e));
    double angel;
    cout << "\nNhap goc quay: ";
    cin >> angel;
    TamGiac B(T);
    B.Xuat(B.Quay(B, angel));
    TamGiac C(T);
    cout << "\nNHap he so thu phong cua tam giac: ";
    int k;
    cin >> k;
    C.Xuat(C.ThuPhong(C, k));
    return 0;
}

