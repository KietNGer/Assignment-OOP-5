#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
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
    void Nhap();
    Point Tinh_tien(Point &P, int a, int b);
    int Lay_hoang_do();
    int Lay_tung_do();
    void Xuat();
    Point Quay(Point &a, Point &b, double angel);
    friend class DaGiac;
};

class DaGiac
{
private:
    int SoDiem;
    Point *p;
public:
    DaGiac();
    DaGiac(const DaGiac &D);
    ~DaGiac();
    void Nhap();
    void Xuat(DaGiac D);
    DaGiac Tinh_tien(DaGiac &D, double a, double b);
    DaGiac Quay(DaGiac &D, double angel);
    DaGiac PhongTo(DaGiac &D, double k);
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

void Point ::Nhap()
{
    cout << "Nhap hoanh do: ";
    cin >> HoanhDo;
    cout << "Nhap tung do: ";
    cin >> TungDo;
}

void Point ::Xuat()
{
    cout << "<" << HoanhDo << "," << TungDo << ">" << endl;
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

DaGiac ::DaGiac()
{

}

DaGiac ::DaGiac(const DaGiac &D)
{
    SoDiem = D.SoDiem;
    p = new Point[SoDiem];
    for(int i = 0; i < D.SoDiem; i++)
    {
        p[i] = D.p[i];
    }
}

DaGiac ::~DaGiac()
{
    delete[] p;
}

void DaGiac ::Nhap()
{
    cout << "Nhap so dinh cua da giac: \n";
    cin >> SoDiem;
    p = new Point[SoDiem];
    for(int i = 0; i < SoDiem; i++)
    {
        cout << "Nhap toa do diem thu: " << i+1 << " : \n";
        p[i].Nhap();
    }
}

void DaGiac ::Xuat(DaGiac D)
{
    cout << "Da giac duoc tao thanh tu cac diem: \n";
    for(int i = 0; i < SoDiem; i++)
    {
        D.p[i].Xuat();
        cout << " ";
    }
    cout << endl;
}

DaGiac DaGiac ::Tinh_tien(DaGiac &D, double d, double e)
{
    for(int i = 0; i < D.SoDiem; i++)
    {
        D.p[i].HoanhDo += d;
        D.p[i].TungDo += e;
    }
    return D;
}

DaGiac DaGiac ::Quay(DaGiac &D, double angel)
{
    Point o(0, 0);
    for(int i = 0; i < D.SoDiem; i++)
    {
        D.p[i] = D.p[i].Quay(D.p[i], o, angel);
    }
    return D;
}

DaGiac DaGiac ::PhongTo(DaGiac &D, double k)
{
    for(int i = 0; i <SoDiem; i++)
    {
        D.p[i].HoanhDo *= k;
        D.p[i].TungDo *= k;
    }
    return D;
}

int main()
{
    DaGiac D;
    D.Nhap();
    D.Xuat(D);
    DaGiac A(D);
    cout << "Nhap toa do de tinh tien: ";
    double d;
    double e;
    cin >> d >> e;
    A.Xuat(A.Tinh_tien(A, d, e));
    DaGiac B(D);
    cout << "Nhap goc xoay: ";
    double angel;
    cin >> angel;
    B.Xuat(B.Quay(B, angel));
    DaGiac C(D);
    cout << "Nhap he so phong thu: ";
    double k;
    cin >> k;
    C.Xuat(C.PhongTo(C, k));
    return 0;
}
