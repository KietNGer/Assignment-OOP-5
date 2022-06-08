#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

class Time
{
private:
    int gio;
    int phut;
    int giay;
public:
    Time();
    Time(int a, int b, int c);
    ~Time();
    void Nhap();
    bool iSDay();
    void Dinh_dang(Time a);
};

Time ::Time()
{
    gio = 0;
    phut = 0;
    giay = 0;
}

Time ::Time(int a, int b, int c)
{
    gio = a;
    phut = b;
    giay = c;
}

Time ::~Time()
{
    gio = 0;
    phut = 0;
    giay = 0;
}

void Time ::Nhap()
{
    cout << "Nhap gio: ";
    cin >> gio;
    cout << "Nhap phut: ";
    cin >> phut;
    cout << "Nhap giay: ";
    cin >> giay;
}

bool Time ::iSDay()
{
    if(gio < 11)
        return true;
    return false;
}

void Time ::Dinh_dang(Time a)
{
    if(a.iSDay())
        cout << a.gio << ":" << a.phut << ":" << a.giay << " AM" << endl;
    else
        cout << a.gio-12 << ":" << a.phut << ":" << a.giay << " PM" << endl;
}

int main()
{
    Time A;
    A.Nhap();
    A.Dinh_dang(A);
    return 0;
}
