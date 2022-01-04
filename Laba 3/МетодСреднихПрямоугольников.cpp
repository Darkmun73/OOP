#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return pow(x,2)+x+1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double lowInt, upInt, stepSize, func, integ;
    int stepCount;
    
    cout << "Введите нижний предел интеграла: ";
    cin >> lowInt;
    cout << "Введите верхний предел интеграла: ";
    cin >> upInt;
    cout << "Введите количество разбиений (для точности вычисления интеграла): ";
    cin >> stepCount;
    while(stepCount<=0)
    {
        cout << "Введите другое число разбиений: ";
        cin >> stepCount;
    }
    stepSize=(upInt-lowInt)/stepCount;
    for(int i=0; i<=(stepCount-1); i++)
    {
        func+=f(lowInt+stepSize*(i+0.5));   
    }
    integ=stepSize*func;
    cout << "Значение интеграла: " << integ;
    return 0;
}
