#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double x, y, z;
    cout << "Введите x: ";
    cin >> x;
    while (pow((x + 4.35),2) == 0) 
    {
       cout << "Введите другое значение x: ";
       cin >> x;
    }
    y=2 * pow(x,2) + 3*x + 8;
    z=pow((3-x),3)/pow((x + 4.35),2) + 10*y + abs(y - 13)/exp(1);
    cout << "y=" << y << "\n" << "z=" << z;
    return 0;
}
