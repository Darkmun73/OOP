#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;
int main()
{
    double a ,b, c;
    double x, y, f;
    a=5.2;
    b=8.13;
    c=7.71;
    cout << "Введите x: ";
    cin >> x;
    y=(x-a)/(b-c);
    if (y<-1) 
    {
        f=(x+1)/(y-1);
    }
    else 
    {
        if((y>=-1)&&(y<1))
        {
            f=5.2*M_PI*y;
        }
        else
        {
            f=(x-1)/(y+1);
        }
    }
    cout << "f=" << f;
    return 0;
}
