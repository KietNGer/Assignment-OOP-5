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
    int HoanhDo;
    int TungDo;
public:
    Point();
    ~Point();
    void Nhap();
    void Tinh_tien(Point &P, int a, int b);
    int Lay_hoang_do();
    int Lay_tung_do();
    void Xuat(Point a);
};

Point ::Point()
{
    HoanhDo = 0;
    TungDo = 0;
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

void Point ::Tinh_tien(Point &P, int a, int b)
{
    P.HoanhDo += a;
    P.TungDo += b;
    cout << "Toa do diem sau khi tinh tien: ";
    P.Xuat(P);
}

int main()
{
    Point A;
    A.Nhap();
    cout << A.Lay_hoang_do() << endl;
    cout << A.Lay_tung_do() << endl;
    A.Xuat(A);
    int a;
    int b;
    cout << "Nhap toa do diem tinh tien: ";
    cin >> a;
    cin >> b;
    cout << "<" << a << "," << b << ">" << endl;
    A.Tinh_tien(A, a, b);
    return 0;
}
