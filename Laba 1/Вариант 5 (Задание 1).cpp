#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double a, b, c;
    double ma, mb, mc;
    a=12.1;
    b=8.82;
    c=10.21;
    ma=sqrt(2*pow(b,2)+2*pow(c,2)-pow(a,2))/2;
    mb=sqrt(2*pow(a,2)+2*pow(c,2)-pow(b,2))/2;
    mc=sqrt(2*pow(b,2)+2*pow(a,2)-pow(c,2))/2;
    cout << "ma=" << ma << "\n" << "mb=" << mb << "\n" << "mc=" << mc;
    return 0;
}
