#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
//Дана матрица размером NxM. Упорядочить ее строки по возрастанию суммы их элементов.

int sum(int* mat, int c) //вычисление суммы элементов в строке
{
    int sm = 0;
    for (int i = 0; i < c; i++)
    {
        sm += mat[i];
    }
    return sm;
}

int main()
{
    int row, column;

    //Ввод числа строк и столбцов
    cout << "Enter number of row: ";
    cin >> row;
    while (cin.fail() || (row < 1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter another number of row: ";
        cin >> row;
    }
    cout << "Enter number of column : ";
    cin >> column;
    while (cin.fail() || (column < 1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter another number of column : ";
        cin >> column;
    }

    //Выделение памяти под матрицу
    int** matrix = new int* [row];
    for (int i = 0; i < row; i++)
        matrix[i] = new int[column];

    //Заполнение матрицы
    srand(time(0));
    for (int count_r = 0; count_r < row; count_r++)
        for (int count_c = 0; count_c < column; count_c++)
            matrix[count_r][count_c] = rand() % 20 + 1;

    //Вывод матрицы без сортировки
    cout << "\n" << "Matrix before sort: " << endl;
    for (int count_r = 0; count_r < row; count_r++)
    {
        for (int count_c = 0; count_c < column; count_c++)
            cout << setw(3) << matrix[count_r][count_c] << "   ";
        cout << endl;
    }

    //Сортировка (упорядочить строки матрицы по возрастанию суммы их элементов)
    for (int count_r1 = 0; count_r1 < (row-1); count_r1++)
    {
        for (int count_r2 = (count_r1+1); count_r2 < row; count_r2++)
        {
            if (sum(matrix[count_r1], column) < sum(matrix[count_r2], column))
                swap(matrix[count_r1], matrix[count_r2]);
        }
    }

    //Вывод матрицы после сортировки
    cout << "\n" << "Matrix after sort: " << endl;
    for (int count_r = 0; count_r < row; count_r++)
    {
        for (int count_c = 0; count_c < column; count_c++)
            cout << setw(3) << matrix[count_r][count_c] << "   ";
        cout << endl;
    }
    
    //Удаление
    for(int i=0; i<row; i++)
        delete[] matrix[i];
    delete[] matrix;
    
    return 0;
}
